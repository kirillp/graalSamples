package pkirill.graalsample;

import org.graalvm.nativeimage.IsolateThread;
import org.graalvm.nativeimage.c.function.CEntryPoint;
import org.graalvm.nativeimage.c.function.CFunctionPointer;
import org.graalvm.nativeimage.c.function.InvokeCFunctionPointer;
import org.graalvm.nativeimage.c.type.CCharPointer;

import java.nio.charset.StandardCharsets;

public class EntryPoints {
  @CEntryPoint
  static int add(IsolateThread thread, int x) {
    return 1 + x;
  }
  @CEntryPoint
  static int sub(IsolateThread thread, int x) {
    return 1 - x;
  }

  @CEntryPoint(builtin=CEntryPoint.Builtin.CREATE_ISOLATE)
  static native IsolateThread createIsolate();

  interface AllocatorFn extends CFunctionPointer {
    @InvokeCFunctionPointer
    CCharPointer call(long size);
  }

  @CEntryPoint
  static CCharPointer getString(IsolateThread thread, AllocatorFn alloc) {
    return stringToNative(alloc, EntryPoints.class.getName());
  }

  static CCharPointer stringToNative(AllocatorFn alloc, String string) {
    byte[] b = string.getBytes(StandardCharsets.UTF_8);
    CCharPointer a =  alloc.call(b.length + 1);
    for (int i = 0; i < b.length; i++) {
      a.write(i, b[i]);
    }
    a.write(b.length, (byte) 0);
    return a;
  }
}
