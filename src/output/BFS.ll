; ModuleID = 'llvm-link'
source_filename = "llvm-link"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.timeval = type { i64, i64 }

@n = global i32 0
@m = global i32 0
@to = global [5005 x i32] zeroinitializer
@next = global [5005 x i32] zeroinitializer
@head = global [1005 x i32] zeroinitializer
@cnt = global i32 0
@que = global [1005 x i32] zeroinitializer
@h = global i32 0
@tail = global i32 0
@inq = global [1005 x i32] zeroinitializer
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

define i32 @quickread() {
bb1:
  %r254 = add i32 0, 0
  %r255 = call i32 @getch()
  %r256 = add i32 %r255, 0
  %r257 = add i32 0, 0
  %r258 = add i32 0, 0
  %r259 = add i32 0, 0
  %r260 = add i32 0, 0
  br label %bb2

bb2:                                              ; preds = %bb8, %bb1
  %r261 = phi i32 [ %r256, %bb1 ], [ %r269, %bb8 ]
  %r262 = phi i32 [ %r260, %bb1 ], [ %r267, %bb8 ]
  %r263 = icmp slt i32 %r261, 48
  br i1 %r263, label %bb3, label %bb5

bb5:                                              ; preds = %bb2
  %r264 = icmp sgt i32 %r261, 57
  br i1 %r264, label %bb3, label %bb4

bb3:                                              ; preds = %bb5, %bb2
  %r265 = icmp eq i32 %r261, 45
  br i1 %r265, label %bb6, label %bb7

bb6:                                              ; preds = %bb3
  %r266 = add i32 1, 0
  br label %bb8

bb7:                                              ; preds = %bb3
  br label %bb8

bb8:                                              ; preds = %bb7, %bb6
  %r267 = phi i32 [ %r266, %bb6 ], [ %r262, %bb7 ]
  %r268 = call i32 @getch()
  %r269 = add i32 %r268, 0
  br label %bb2

bb4:                                              ; preds = %bb5
  br label %bb9

bb9:                                              ; preds = %bb10, %bb4
  %r270 = phi i32 [ %r261, %bb4 ], [ %r279, %bb10 ]
  %r271 = phi i32 [ %r258, %bb4 ], [ %r277, %bb10 ]
  %r272 = icmp sge i32 %r270, 48
  br i1 %r272, label %bb12, label %bb11

bb12:                                             ; preds = %bb9
  %r273 = icmp sle i32 %r270, 57
  br i1 %r273, label %bb10, label %bb11

bb10:                                             ; preds = %bb12
  %r274 = mul i32 %r271, 10
  %r275 = add i32 %r274, %r270
  %r276 = sub i32 %r275, 48
  %r277 = add i32 %r276, 0
  %r278 = call i32 @getch()
  %r279 = add i32 %r278, 0
  br label %bb9

bb11:                                             ; preds = %bb12, %bb9
  %r280 = icmp ne i32 %r262, 0
  br i1 %r280, label %bb13, label %bb14

bb13:                                             ; preds = %bb11
  %r281 = sub i32 0, %r271
  ret i32 %r281

bb14:                                             ; preds = %bb11
  ret i32 %r271
}

define void @addedge(i32 %r126, i32 %r128) {
bb16:
  %r282 = add i32 0, 0
  %r283 = add i32 %r126, 0
  %r284 = add i32 0, 0
  %r285 = add i32 %r128, 0
  %r286 = load i32, ptr @cnt, align 4
  %r132 = getelementptr [5005 x i32], ptr @to, i32 0, i32 %r286
  store i32 %r285, ptr %r132, align 4
  %r134 = getelementptr [1005 x i32], ptr @head, i32 0, i32 %r283
  %r287 = load i32, ptr %r134, align 4
  %r288 = load i32, ptr @cnt, align 4
  %r137 = getelementptr [5005 x i32], ptr @next, i32 0, i32 %r288
  store i32 %r287, ptr %r137, align 4
  %r289 = load i32, ptr @cnt, align 4
  %r140 = getelementptr [1005 x i32], ptr @head, i32 0, i32 %r283
  store i32 %r289, ptr %r140, align 4
  %r290 = load i32, ptr @cnt, align 4
  %r291 = add i32 %r290, 1
  store i32 %r291, ptr @cnt, align 4
  %r292 = load i32, ptr @cnt, align 4
  %r145 = getelementptr [5005 x i32], ptr @to, i32 0, i32 %r292
  store i32 %r283, ptr %r145, align 4
  %r147 = getelementptr [1005 x i32], ptr @head, i32 0, i32 %r285
  %r293 = load i32, ptr %r147, align 4
  %r294 = load i32, ptr @cnt, align 4
  %r150 = getelementptr [5005 x i32], ptr @next, i32 0, i32 %r294
  store i32 %r293, ptr %r150, align 4
  %r295 = load i32, ptr @cnt, align 4
  %r153 = getelementptr [1005 x i32], ptr @head, i32 0, i32 %r285
  store i32 %r295, ptr %r153, align 4
  %r296 = load i32, ptr @cnt, align 4
  %r297 = add i32 %r296, 1
  store i32 %r297, ptr @cnt, align 4
  ret void
}

define void @init() {
bb17:
  %r298 = add i32 0, 0
  %r299 = add i32 0, 0
  br label %bb18

bb18:                                             ; preds = %bb19, %bb17
  %r300 = phi i32 [ %r299, %bb17 ], [ %r304, %bb19 ]
  %r301 = icmp slt i32 %r300, 1005
  br i1 %r301, label %bb19, label %bb20

bb19:                                             ; preds = %bb18
  %r302 = sub i32 0, 1
  %r161 = getelementptr [1005 x i32], ptr @head, i32 0, i32 %r300
  store i32 %r302, ptr %r161, align 4
  %r303 = add i32 %r300, 1
  %r304 = add i32 %r303, 0
  br label %bb18

bb20:                                             ; preds = %bb18
  ret void
}

define void @inqueue(i32 %r164) {
bb21:
  %r305 = add i32 0, 0
  %r306 = add i32 %r164, 0
  %r167 = getelementptr [1005 x i32], ptr @inq, i32 0, i32 %r306
  store i32 1, ptr %r167, align 4
  %r307 = load i32, ptr @tail, align 4
  %r308 = add i32 %r307, 1
  store i32 %r308, ptr @tail, align 4
  %r309 = load i32, ptr @tail, align 4
  %r172 = getelementptr [1005 x i32], ptr @que, i32 0, i32 %r309
  store i32 %r306, ptr %r172, align 4
  ret void
}

define i32 @popqueue() {
bb22:
  %r310 = load i32, ptr @h, align 4
  %r311 = add i32 %r310, 1
  store i32 %r311, ptr @h, align 4
  %r312 = add i32 0, 0
  %r313 = load i32, ptr @h, align 4
  %r177 = getelementptr [1005 x i32], ptr @que, i32 0, i32 %r313
  %r314 = load i32, ptr %r177, align 4
  %r315 = add i32 %r314, 0
  %r316 = load i32, ptr @h, align 4
  %r180 = getelementptr [1005 x i32], ptr @que, i32 0, i32 %r316
  %r317 = load i32, ptr %r180, align 4
  ret i32 %r317
}

define i32 @same(i32 %r182, i32 %r184) {
bb23:
  %r318 = add i32 0, 0
  %r319 = add i32 %r182, 0
  %r320 = add i32 0, 0
  %r321 = add i32 %r184, 0
  store i32 0, ptr @h, align 4
  store i32 0, ptr @tail, align 4
  call void @inqueue(i32 %r319)
  %r322 = add i32 0, 0
  %r323 = add i32 0, 0
  %r324 = add i32 0, 0
  %r325 = add i32 0, 0
  %r326 = add i32 0, 0
  %r327 = add i32 0, 0
  %r328 = add i32 0, 0
  %r329 = add i32 0, 0
  br label %bb24

bb24:                                             ; preds = %bb32, %bb23
  %r330 = phi i32 [ %r323, %bb23 ], [ %r338, %bb32 ]
  %r331 = load i32, ptr @h, align 4
  %r332 = load i32, ptr @tail, align 4
  %r333 = icmp slt i32 %r331, %r332
  br i1 %r333, label %bb25, label %bb26

bb25:                                             ; preds = %bb24
  %r334 = call i32 @popqueue()
  %r335 = add i32 %r334, 0
  %r336 = icmp eq i32 %r335, %r321
  br i1 %r336, label %bb27, label %bb28

bb27:                                             ; preds = %bb25
  %r337 = add i32 1, 0
  br label %bb29

bb28:                                             ; preds = %bb25
  br label %bb29

bb29:                                             ; preds = %bb28, %bb27
  %r338 = phi i32 [ %r337, %bb27 ], [ %r330, %bb28 ]
  %r199 = getelementptr [1005 x i32], ptr @head, i32 0, i32 %r335
  %r339 = load i32, ptr %r199, align 4
  %r340 = add i32 %r339, 0
  br label %bb30

bb30:                                             ; preds = %bb35, %bb29
  %r341 = phi i32 [ %r340, %bb29 ], [ %r350, %bb35 ]
  %r342 = sub i32 0, 1
  %r343 = icmp ne i32 %r341, %r342
  br i1 %r343, label %bb31, label %bb32

bb31:                                             ; preds = %bb30
  %r205 = getelementptr [5005 x i32], ptr @to, i32 0, i32 %r341
  %r344 = load i32, ptr %r205, align 4
  %r345 = add i32 %r344, 0
  %r208 = getelementptr [1005 x i32], ptr @inq, i32 0, i32 %r345
  %r346 = load i32, ptr %r208, align 4
  %r347 = icmp eq i32 %r346, 0
  br i1 %r347, label %bb33, label %bb34

bb33:                                             ; preds = %bb31
  %r212 = getelementptr [5005 x i32], ptr @to, i32 0, i32 %r341
  %r348 = load i32, ptr %r212, align 4
  call void @inqueue(i32 %r348)
  br label %bb35

bb34:                                             ; preds = %bb31
  br label %bb35

bb35:                                             ; preds = %bb34, %bb33
  %r215 = getelementptr [5005 x i32], ptr @next, i32 0, i32 %r341
  %r349 = load i32, ptr %r215, align 4
  %r350 = add i32 %r349, 0
  br label %bb30

bb32:                                             ; preds = %bb30
  br label %bb24

bb26:                                             ; preds = %bb24
  %r351 = add i32 0, 0
  br label %bb36

bb36:                                             ; preds = %bb37, %bb26
  %r352 = phi i32 [ %r351, %bb26 ], [ %r358, %bb37 ]
  %r353 = load i32, ptr @tail, align 4
  %r354 = icmp sle i32 %r352, %r353
  br i1 %r354, label %bb37, label %bb38

bb37:                                             ; preds = %bb36
  %r221 = getelementptr [1005 x i32], ptr @que, i32 0, i32 %r352
  %r355 = load i32, ptr %r221, align 4
  %r356 = add i32 %r355, 0
  %r224 = getelementptr [1005 x i32], ptr @inq, i32 0, i32 %r356
  store i32 0, ptr %r224, align 4
  %r357 = add i32 %r352, 1
  %r358 = add i32 %r357, 0
  br label %bb36

bb38:                                             ; preds = %bb36
  ret i32 %r330
}

define i32 @main() {
bb39:
  %r359 = call i32 @quickread()
  store i32 %r359, ptr @n, align 4
  %r360 = call i32 @quickread()
  store i32 %r360, ptr @m, align 4
  call void @_sysy_starttime(i32 97)
  call void @init()
  %r361 = add i32 0, 0
  %r362 = add i32 0, 0
  %r363 = add i32 0, 0
  %r364 = add i32 0, 0
  %r365 = add i32 0, 0
  %r366 = add i32 0, 0
  br label %bb40

bb40:                                             ; preds = %bb49, %bb39
  %r367 = load i32, ptr @m, align 4
  %r368 = icmp ne i32 %r367, 0
  br i1 %r368, label %bb41, label %bb42

bb41:                                             ; preds = %bb40
  %r369 = call i32 @getch()
  %r370 = add i32 %r369, 0
  br label %bb43

bb43:                                             ; preds = %bb44, %bb41
  %r371 = phi i32 [ %r370, %bb41 ], [ %r375, %bb44 ]
  %r372 = icmp ne i32 %r371, 81
  br i1 %r372, label %bb46, label %bb45

bb46:                                             ; preds = %bb43
  %r373 = icmp ne i32 %r371, 85
  br i1 %r373, label %bb44, label %bb45

bb44:                                             ; preds = %bb46
  %r374 = call i32 @getch()
  %r375 = add i32 %r374, 0
  br label %bb43

bb45:                                             ; preds = %bb46, %bb43
  %r376 = icmp eq i32 %r371, 81
  br i1 %r376, label %bb47, label %bb48

bb47:                                             ; preds = %bb45
  %r377 = call i32 @quickread()
  %r378 = add i32 %r377, 0
  %r379 = call i32 @quickread()
  %r380 = add i32 %r379, 0
  %r381 = call i32 @same(i32 %r378, i32 %r380)
  call void @putint(i32 %r381)
  call void @putch(i32 10)
  br label %bb49

bb48:                                             ; preds = %bb45
  %r384 = call i32 @quickread()
  %r385 = add i32 %r384, 0
  %r386 = call i32 @quickread()
  %r387 = add i32 %r386, 0
  call void @addedge(i32 %r385, i32 %r387)
  br label %bb49

bb49:                                             ; preds = %bb48, %bb47
  %r382 = load i32, ptr @m, align 4
  %r383 = sub i32 %r382, 1
  store i32 %r383, ptr @m, align 4
  br label %bb40

bb42:                                             ; preds = %bb40
  call void @_sysy_stoptime(i32 117)
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
