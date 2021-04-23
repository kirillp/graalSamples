package pkirill.graalsample;

import org.graalvm.nativeimage.CurrentIsolate;
import org.graalvm.nativeimage.IsolateThread;
import org.graalvm.nativeimage.c.function.CEntryPoint;

public class EntryPoints {

  @CEntryPoint(builtin=CEntryPoint.Builtin.CREATE_ISOLATE)
  static native IsolateThread createIsolate();

  public static void main(String[] args) {
    System.out.println("Main: isolate = " + Long.toHexString(CurrentIsolate.getCurrentThread().rawValue()));
  }
}
