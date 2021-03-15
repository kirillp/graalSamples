package pkirill.graalsample;

import org.graalvm.nativeimage.IsolateThread;
import org.graalvm.nativeimage.c.function.CEntryPoint;

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

  @CEntryPoint
  static void kotlin(IsolateThread thread) {
    KotlinTestKt.main();
  }
}
