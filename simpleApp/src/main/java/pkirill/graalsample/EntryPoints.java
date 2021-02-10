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
}
