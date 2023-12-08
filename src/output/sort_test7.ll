; ModuleID = 'llvm-link'
source_filename = "llvm-link"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.timeval = type { i64, i64 }

@n = global i32 0
@llvm.global_ctors = appending global [1 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 65535, ptr @before_main, ptr null }]
@llvm.global_dtors = appending global [1 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 65535, ptr @after_main, ptr null }]
@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"%d:\00", align 1
@.str.3 = private unnamed_addr constant [4 x i8] c" %d\00", align 1
@.str.4 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@_sysy_us = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_s = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_m = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_h = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_idx = dso_local global i32 0, align 4
@stderr = external global ptr, align 8
@.str.5 = private unnamed_addr constant [35 x i8] c"Timer@%04d-%04d: %dH-%dM-%dS-%dus\0A\00", align 1
@_sysy_l1 = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_l2 = dso_local global [1024 x i32] zeroinitializer, align 16
@.str.6 = private unnamed_addr constant [25 x i8] c"TOTAL: %dH-%dM-%dS-%dus\0A\00", align 1
@_sysy_start = dso_local global %struct.timeval zeroinitializer, align 8
@_sysy_end = dso_local global %struct.timeval zeroinitializer, align 8

define i32 @Merge(ptr %r100, i32 %r101, i32 %r103, i32 %r105) {
bb1:
  %r260 = add i32 0, 0
  %r261 = add i32 0, 0
  %r262 = add i32 %r101, 0
  %r263 = add i32 0, 0
  %r264 = add i32 %r103, 0
  %r265 = add i32 0, 0
  %r266 = add i32 %r105, 0
  %r267 = add i32 0, 0
  %r268 = sub i32 %r264, %r262
  %r269 = add i32 %r268, 1
  %r270 = add i32 %r269, 0
  %r271 = add i32 0, 0
  %r272 = sub i32 %r266, %r264
  %r273 = add i32 %r272, 0
  %r116 = alloca [10 x i32], align 4
  %r117 = alloca [10 x i32], align 4
  %r274 = add i32 0, 0
  %r275 = add i32 0, 0
  %r276 = add i32 0, 0
  %r277 = add i32 0, 0
  %r278 = add i32 0, 0
  br label %bb2

bb2:                                              ; preds = %bb3, %bb1
  %r279 = phi i32 [ %r275, %bb1 ], [ %r285, %bb3 ]
  %r280 = icmp slt i32 %r279, %r270
  br i1 %r280, label %bb3, label %bb4

bb3:                                              ; preds = %bb2
  %r281 = add i32 %r279, %r262
  %r282 = add i32 %r281, 0
  %r128 = getelementptr i32, ptr %r100, i32 %r282
  %r283 = load i32, ptr %r128, align 4
  %r131 = getelementptr [10 x i32], ptr %r116, i32 0, i32 %r279
  store i32 %r283, ptr %r131, align 4
  %r284 = add i32 %r279, 1
  %r285 = add i32 %r284, 0
  br label %bb2

bb4:                                              ; preds = %bb2
  br label %bb5

bb5:                                              ; preds = %bb6, %bb4
  %r286 = phi i32 [ %r277, %bb4 ], [ %r293, %bb6 ]
  %r287 = icmp slt i32 %r286, %r273
  br i1 %r287, label %bb6, label %bb7

bb6:                                              ; preds = %bb5
  %r288 = add i32 %r286, %r264
  %r289 = add i32 %r288, 1
  %r290 = add i32 %r289, 0
  %r142 = getelementptr i32, ptr %r100, i32 %r290
  %r291 = load i32, ptr %r142, align 4
  %r145 = getelementptr [10 x i32], ptr %r117, i32 0, i32 %r286
  store i32 %r291, ptr %r145, align 4
  %r292 = add i32 %r286, 1
  %r293 = add i32 %r292, 0
  br label %bb5

bb7:                                              ; preds = %bb5
  %r294 = add i32 0, 0
  %r295 = add i32 0, 0
  %r296 = add i32 %r262, 0
  br label %bb8

bb8:                                              ; preds = %bb14, %bb7
  %r297 = phi i32 [ %r294, %bb7 ], [ %r311, %bb14 ]
  %r298 = phi i32 [ %r296, %bb7 ], [ %r312, %bb14 ]
  %r299 = phi i32 [ %r295, %bb7 ], [ %r313, %bb14 ]
  %r300 = icmp ne i32 %r297, %r270
  br i1 %r300, label %bb11, label %bb10

bb11:                                             ; preds = %bb8
  %r301 = icmp ne i32 %r299, %r273
  br i1 %r301, label %bb9, label %bb10

bb9:                                              ; preds = %bb11
  %r157 = getelementptr [10 x i32], ptr %r116, i32 0, i32 %r297
  %r302 = load i32, ptr %r157, align 4
  %r160 = getelementptr [10 x i32], ptr %r117, i32 0, i32 %r299
  %r303 = load i32, ptr %r160, align 4
  %r304 = add i32 %r303, 1
  %r305 = icmp slt i32 %r302, %r304
  br i1 %r305, label %bb12, label %bb13

bb12:                                             ; preds = %bb9
  %r165 = getelementptr [10 x i32], ptr %r116, i32 0, i32 %r297
  %r306 = load i32, ptr %r165, align 4
  %r168 = getelementptr i32, ptr %r100, i32 %r298
  store i32 %r306, ptr %r168, align 4
  %r307 = add i32 %r298, 1
  %r308 = add i32 %r307, 0
  %r309 = add i32 %r297, 1
  %r310 = add i32 %r309, 0
  br label %bb14

bb13:                                             ; preds = %bb9
  %r174 = getelementptr [10 x i32], ptr %r117, i32 0, i32 %r299
  %r314 = load i32, ptr %r174, align 4
  %r177 = getelementptr i32, ptr %r100, i32 %r298
  store i32 %r314, ptr %r177, align 4
  %r315 = add i32 %r298, 1
  %r316 = add i32 %r315, 0
  %r317 = add i32 %r299, 1
  %r318 = add i32 %r317, 0
  br label %bb14

bb14:                                             ; preds = %bb13, %bb12
  %r311 = phi i32 [ %r310, %bb12 ], [ %r297, %bb13 ]
  %r312 = phi i32 [ %r308, %bb12 ], [ %r316, %bb13 ]
  %r313 = phi i32 [ %r299, %bb12 ], [ %r318, %bb13 ]
  br label %bb8

bb10:                                             ; preds = %bb11, %bb8
  br label %bb15

bb15:                                             ; preds = %bb16, %bb10
  %r319 = phi i32 [ %r297, %bb10 ], [ %r326, %bb16 ]
  %r320 = phi i32 [ %r298, %bb10 ], [ %r324, %bb16 ]
  %r321 = icmp slt i32 %r319, %r270
  br i1 %r321, label %bb16, label %bb17

bb16:                                             ; preds = %bb15
  %r186 = getelementptr [10 x i32], ptr %r116, i32 0, i32 %r319
  %r322 = load i32, ptr %r186, align 4
  %r189 = getelementptr i32, ptr %r100, i32 %r320
  store i32 %r322, ptr %r189, align 4
  %r323 = add i32 %r320, 1
  %r324 = add i32 %r323, 0
  %r325 = add i32 %r319, 1
  %r326 = add i32 %r325, 0
  br label %bb15

bb17:                                             ; preds = %bb15
  br label %bb18

bb18:                                             ; preds = %bb19, %bb17
  %r327 = phi i32 [ %r320, %bb17 ], [ %r332, %bb19 ]
  %r328 = phi i32 [ %r299, %bb17 ], [ %r334, %bb19 ]
  %r329 = icmp slt i32 %r328, %r273
  br i1 %r329, label %bb19, label %bb20

bb19:                                             ; preds = %bb18
  %r198 = getelementptr [10 x i32], ptr %r117, i32 0, i32 %r328
  %r330 = load i32, ptr %r198, align 4
  %r201 = getelementptr i32, ptr %r100, i32 %r327
  store i32 %r330, ptr %r201, align 4
  %r331 = add i32 %r327, 1
  %r332 = add i32 %r331, 0
  %r333 = add i32 %r328, 1
  %r334 = add i32 %r333, 0
  br label %bb18

bb20:                                             ; preds = %bb18
  ret i32 0
}

define i32 @MergeSort(ptr %r206, i32 %r207, i32 %r209) {
bb21:
  %r335 = add i32 0, 0
  %r336 = add i32 0, 0
  %r337 = add i32 0, 0
  %r338 = add i32 %r207, 0
  %r339 = add i32 0, 0
  %r340 = add i32 %r209, 0
  %r341 = icmp slt i32 %r338, %r340
  br i1 %r341, label %bb22, label %bb23

bb22:                                             ; preds = %bb21
  %r342 = add i32 %r338, %r340
  %r343 = sdiv i32 %r342, 2
  %r344 = add i32 %r343, 0
  %r345 = call i32 @MergeSort(ptr %r206, i32 %r338, i32 %r344)
  %r346 = add i32 %r345, 0
  %r347 = add i32 %r344, 1
  %r348 = add i32 %r347, 0
  %r349 = call i32 @MergeSort(ptr %r206, i32 %r348, i32 %r340)
  %r350 = add i32 %r349, 0
  %r351 = call i32 @Merge(ptr %r206, i32 %r338, i32 %r344, i32 %r340)
  %r352 = add i32 %r351, 0
  br label %bb24

bb23:                                             ; preds = %bb21
  br label %bb24

bb24:                                             ; preds = %bb23, %bb22
  ret i32 0
}

define i32 @main() {
bb25:
  call void @_sysy_starttime(i32 71)
  store i32 10, ptr @n, align 4
  %r232 = alloca [10 x i32], align 4
  %r233 = getelementptr [10 x i32], ptr %r232, i32 0, i32 0
  store i32 4, ptr %r233, align 4
  %r234 = getelementptr [10 x i32], ptr %r232, i32 0, i32 1
  store i32 3, ptr %r234, align 4
  %r235 = getelementptr [10 x i32], ptr %r232, i32 0, i32 2
  store i32 9, ptr %r235, align 4
  %r236 = getelementptr [10 x i32], ptr %r232, i32 0, i32 3
  store i32 2, ptr %r236, align 4
  %r237 = getelementptr [10 x i32], ptr %r232, i32 0, i32 4
  store i32 0, ptr %r237, align 4
  %r238 = getelementptr [10 x i32], ptr %r232, i32 0, i32 5
  store i32 1, ptr %r238, align 4
  %r239 = getelementptr [10 x i32], ptr %r232, i32 0, i32 6
  store i32 6, ptr %r239, align 4
  %r240 = getelementptr [10 x i32], ptr %r232, i32 0, i32 7
  store i32 5, ptr %r240, align 4
  %r241 = getelementptr [10 x i32], ptr %r232, i32 0, i32 8
  store i32 7, ptr %r241, align 4
  %r242 = getelementptr [10 x i32], ptr %r232, i32 0, i32 9
  store i32 8, ptr %r242, align 4
  %r353 = add i32 0, 0
  %r354 = add i32 0, 0
  %r355 = add i32 0, 0
  %r356 = load i32, ptr @n, align 4
  %r357 = sub i32 %r356, 1
  %r358 = add i32 %r357, 0
  %r359 = call i32 @MergeSort(ptr %r232, i32 %r354, i32 %r358)
  %r360 = add i32 %r359, 0
  br label %bb26

bb26:                                             ; preds = %bb27, %bb25
  %r361 = phi i32 [ %r360, %bb25 ], [ %r368, %bb27 ]
  %r362 = load i32, ptr @n, align 4
  %r363 = icmp slt i32 %r361, %r362
  br i1 %r363, label %bb27, label %bb28

bb27:                                             ; preds = %bb26
  %r254 = getelementptr [10 x i32], ptr %r232, i32 0, i32 %r361
  %r364 = load i32, ptr %r254, align 4
  %r365 = add i32 %r364, 0
  call void @putint(i32 %r365)
  %r366 = add i32 10, 0
  call void @putch(i32 %r366)
  %r367 = add i32 %r361, 1
  %r368 = add i32 %r367, 0
  br label %bb26

bb28:                                             ; preds = %bb26
  call void @_sysy_stoptime(i32 97)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @before_main() #0 {
  %1 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  br label %2

2:                                                ; preds = %18, %0
  %3 = load i32, ptr %1, align 4
  %4 = icmp slt i32 %3, 1024
  br i1 %4, label %5, label %21

5:                                                ; preds = %2
  %6 = load i32, ptr %1, align 4
  %7 = sext i32 %6 to i64
  %8 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %7
  store i32 0, ptr %8, align 4
  %9 = load i32, ptr %1, align 4
  %10 = sext i32 %9 to i64
  %11 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %10
  store i32 0, ptr %11, align 4
  %12 = load i32, ptr %1, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %13
  store i32 0, ptr %14, align 4
  %15 = load i32, ptr %1, align 4
  %16 = sext i32 %15 to i64
  %17 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %16
  store i32 0, ptr %17, align 4
  br label %18

18:                                               ; preds = %5
  %19 = load i32, ptr %1, align 4
  %20 = add nsw i32 %19, 1
  store i32 %20, ptr %1, align 4
  br label %2, !llvm.loop !6

21:                                               ; preds = %2
  store i32 1, ptr @_sysy_idx, align 4
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @after_main() #0 {
  %1 = alloca i32, align 4
  store i32 1, ptr %1, align 4
  br label %2

2:                                                ; preds = %63, %0
  %3 = load i32, ptr %1, align 4
  %4 = load i32, ptr @_sysy_idx, align 4
  %5 = icmp slt i32 %3, %4
  br i1 %5, label %6, label %66

6:                                                ; preds = %2
  %7 = load ptr, ptr @stderr, align 8
  %8 = load i32, ptr %1, align 4
  %9 = sext i32 %8 to i64
  %10 = getelementptr inbounds [1024 x i32], ptr @_sysy_l1, i64 0, i64 %9
  %11 = load i32, ptr %10, align 4
  %12 = load i32, ptr %1, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds [1024 x i32], ptr @_sysy_l2, i64 0, i64 %13
  %15 = load i32, ptr %14, align 4
  %16 = load i32, ptr %1, align 4
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %17
  %19 = load i32, ptr %18, align 4
  %20 = load i32, ptr %1, align 4
  %21 = sext i32 %20 to i64
  %22 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %21
  %23 = load i32, ptr %22, align 4
  %24 = load i32, ptr %1, align 4
  %25 = sext i32 %24 to i64
  %26 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %25
  %27 = load i32, ptr %26, align 4
  %28 = load i32, ptr %1, align 4
  %29 = sext i32 %28 to i64
  %30 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %29
  %31 = load i32, ptr %30, align 4
  %32 = call i32 (ptr, ptr, ...) @fprintf(ptr noundef %7, ptr noundef @.str.5, i32 noundef %11, i32 noundef %15, i32 noundef %19, i32 noundef %23, i32 noundef %27, i32 noundef %31)
  %33 = load i32, ptr %1, align 4
  %34 = sext i32 %33 to i64
  %35 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %34
  %36 = load i32, ptr %35, align 4
  %37 = load i32, ptr @_sysy_us, align 16
  %38 = add nsw i32 %37, %36
  store i32 %38, ptr @_sysy_us, align 16
  %39 = load i32, ptr %1, align 4
  %40 = sext i32 %39 to i64
  %41 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %40
  %42 = load i32, ptr %41, align 4
  %43 = load i32, ptr @_sysy_s, align 16
  %44 = add nsw i32 %43, %42
  store i32 %44, ptr @_sysy_s, align 16
  %45 = load i32, ptr @_sysy_us, align 16
  %46 = srem i32 %45, 1000000
  store i32 %46, ptr @_sysy_us, align 16
  %47 = load i32, ptr %1, align 4
  %48 = sext i32 %47 to i64
  %49 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %48
  %50 = load i32, ptr %49, align 4
  %51 = load i32, ptr @_sysy_m, align 16
  %52 = add nsw i32 %51, %50
  store i32 %52, ptr @_sysy_m, align 16
  %53 = load i32, ptr @_sysy_s, align 16
  %54 = srem i32 %53, 60
  store i32 %54, ptr @_sysy_s, align 16
  %55 = load i32, ptr %1, align 4
  %56 = sext i32 %55 to i64
  %57 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %56
  %58 = load i32, ptr %57, align 4
  %59 = load i32, ptr @_sysy_h, align 16
  %60 = add nsw i32 %59, %58
  store i32 %60, ptr @_sysy_h, align 16
  %61 = load i32, ptr @_sysy_m, align 16
  %62 = srem i32 %61, 60
  store i32 %62, ptr @_sysy_m, align 16
  br label %63

63:                                               ; preds = %6
  %64 = load i32, ptr %1, align 4
  %65 = add nsw i32 %64, 1
  store i32 %65, ptr %1, align 4
  br label %2, !llvm.loop !8

66:                                               ; preds = %2
  %67 = load ptr, ptr @stderr, align 8
  %68 = load i32, ptr @_sysy_h, align 16
  %69 = load i32, ptr @_sysy_m, align 16
  %70 = load i32, ptr @_sysy_s, align 16
  %71 = load i32, ptr @_sysy_us, align 16
  %72 = call i32 (ptr, ptr, ...) @fprintf(ptr noundef %67, ptr noundef @.str.6, i32 noundef %68, i32 noundef %69, i32 noundef %70, i32 noundef %71)
  ret void
}

declare i32 @fprintf(ptr noundef, ptr noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @getint() #0 {
  %1 = alloca i32, align 4
  %2 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str, ptr noundef %1)
  %3 = load i32, ptr %1, align 4
  ret i32 %3
}

declare i32 @__isoc99_scanf(ptr noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @getch() #0 {
  %1 = alloca i8, align 1
  %2 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str.1, ptr noundef %1)
  %3 = load i8, ptr %1, align 1
  %4 = sext i8 %3 to i32
  ret i32 %4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @getarray(ptr noundef %0) #0 {
  %2 = alloca ptr, align 8
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store ptr %0, ptr %2, align 8
  %5 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str, ptr noundef %3)
  store i32 0, ptr %4, align 4
  br label %6

6:                                                ; preds = %16, %1
  %7 = load i32, ptr %4, align 4
  %8 = load i32, ptr %3, align 4
  %9 = icmp slt i32 %7, %8
  br i1 %9, label %10, label %19

10:                                               ; preds = %6
  %11 = load ptr, ptr %2, align 8
  %12 = load i32, ptr %4, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds i32, ptr %11, i64 %13
  %15 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str, ptr noundef %14)
  br label %16

16:                                               ; preds = %10
  %17 = load i32, ptr %4, align 4
  %18 = add nsw i32 %17, 1
  store i32 %18, ptr %4, align 4
  br label %6, !llvm.loop !9

19:                                               ; preds = %6
  %20 = load i32, ptr %3, align 4
  ret i32 %20
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @putint(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %3)
  ret void
}

declare i32 @printf(ptr noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @putch(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %3)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @putarray(i32 noundef %0, ptr noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca ptr, align 8
  %5 = alloca i32, align 4
  store i32 %0, ptr %3, align 4
  store ptr %1, ptr %4, align 8
  %6 = load i32, ptr %3, align 4
  %7 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %6)
  store i32 0, ptr %5, align 4
  br label %8

8:                                                ; preds = %19, %2
  %9 = load i32, ptr %5, align 4
  %10 = load i32, ptr %3, align 4
  %11 = icmp slt i32 %9, %10
  br i1 %11, label %12, label %22

12:                                               ; preds = %8
  %13 = load ptr, ptr %4, align 8
  %14 = load i32, ptr %5, align 4
  %15 = sext i32 %14 to i64
  %16 = getelementptr inbounds i32, ptr %13, i64 %15
  %17 = load i32, ptr %16, align 4
  %18 = call i32 (ptr, ...) @printf(ptr noundef @.str.3, i32 noundef %17)
  br label %19

19:                                               ; preds = %12
  %20 = load i32, ptr %5, align 4
  %21 = add nsw i32 %20, 1
  store i32 %21, ptr %5, align 4
  br label %8, !llvm.loop !10

22:                                               ; preds = %8
  %23 = call i32 (ptr, ...) @printf(ptr noundef @.str.4)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_sysy_starttime(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = load i32, ptr @_sysy_idx, align 4
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds [1024 x i32], ptr @_sysy_l1, i64 0, i64 %5
  store i32 %3, ptr %6, align 4
  %7 = call i32 @gettimeofday(ptr noundef @_sysy_start, ptr noundef null) #3
  ret void
}

; Function Attrs: nounwind
declare i32 @gettimeofday(ptr noundef, ptr noundef) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_sysy_stoptime(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = call i32 @gettimeofday(ptr noundef @_sysy_end, ptr noundef null) #3
  %4 = load i32, ptr %2, align 4
  %5 = load i32, ptr @_sysy_idx, align 4
  %6 = sext i32 %5 to i64
  %7 = getelementptr inbounds [1024 x i32], ptr @_sysy_l2, i64 0, i64 %6
  store i32 %4, ptr %7, align 4
  %8 = load i64, ptr @_sysy_end, align 8
  %9 = load i64, ptr @_sysy_start, align 8
  %10 = sub nsw i64 %8, %9
  %11 = mul nsw i64 1000000, %10
  %12 = load i64, ptr getelementptr inbounds (%struct.timeval, ptr @_sysy_end, i32 0, i32 1), align 8
  %13 = add nsw i64 %11, %12
  %14 = load i64, ptr getelementptr inbounds (%struct.timeval, ptr @_sysy_start, i32 0, i32 1), align 8
  %15 = sub nsw i64 %13, %14
  %16 = load i32, ptr @_sysy_idx, align 4
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %17
  %19 = load i32, ptr %18, align 4
  %20 = sext i32 %19 to i64
  %21 = add nsw i64 %20, %15
  %22 = trunc i64 %21 to i32
  store i32 %22, ptr %18, align 4
  %23 = load i32, ptr @_sysy_idx, align 4
  %24 = sext i32 %23 to i64
  %25 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %24
  %26 = load i32, ptr %25, align 4
  %27 = sdiv i32 %26, 1000000
  %28 = load i32, ptr @_sysy_idx, align 4
  %29 = sext i32 %28 to i64
  %30 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %29
  %31 = load i32, ptr %30, align 4
  %32 = add nsw i32 %31, %27
  store i32 %32, ptr %30, align 4
  %33 = load i32, ptr @_sysy_idx, align 4
  %34 = sext i32 %33 to i64
  %35 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %34
  %36 = load i32, ptr %35, align 4
  %37 = srem i32 %36, 1000000
  store i32 %37, ptr %35, align 4
  %38 = load i32, ptr @_sysy_idx, align 4
  %39 = sext i32 %38 to i64
  %40 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %39
  %41 = load i32, ptr %40, align 4
  %42 = sdiv i32 %41, 60
  %43 = load i32, ptr @_sysy_idx, align 4
  %44 = sext i32 %43 to i64
  %45 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %44
  %46 = load i32, ptr %45, align 4
  %47 = add nsw i32 %46, %42
  store i32 %47, ptr %45, align 4
  %48 = load i32, ptr @_sysy_idx, align 4
  %49 = sext i32 %48 to i64
  %50 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %49
  %51 = load i32, ptr %50, align 4
  %52 = srem i32 %51, 60
  store i32 %52, ptr %50, align 4
  %53 = load i32, ptr @_sysy_idx, align 4
  %54 = sext i32 %53 to i64
  %55 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %54
  %56 = load i32, ptr %55, align 4
  %57 = sdiv i32 %56, 60
  %58 = load i32, ptr @_sysy_idx, align 4
  %59 = sext i32 %58 to i64
  %60 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %59
  %61 = load i32, ptr %60, align 4
  %62 = add nsw i32 %61, %57
  store i32 %62, ptr %60, align 4
  %63 = load i32, ptr @_sysy_idx, align 4
  %64 = sext i32 %63 to i64
  %65 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %64
  %66 = load i32, ptr %65, align 4
  %67 = srem i32 %66, 60
  store i32 %67, ptr %65, align 4
  %68 = load i32, ptr @_sysy_idx, align 4
  %69 = add nsw i32 %68, 1
  store i32 %69, ptr @_sysy_idx, align 4
  ret void
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1, !2, !3, !4, !5}

!0 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 8, !"PIC Level", i32 2}
!3 = !{i32 7, !"PIE Level", i32 2}
!4 = !{i32 7, !"uwtable", i32 1}
!5 = !{i32 7, !"frame-pointer", i32 2}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
!9 = distinct !{!9, !7}
!10 = distinct !{!10, !7}
