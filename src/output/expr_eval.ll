; ModuleID = 'llvm-link'
source_filename = "llvm-link"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.timeval = type { i64, i64 }

@TOKEN_NUM = global i32 0
@TOKEN_OTHER = global i32 1
@last_char = global i32 32
@num = global i32 0
@other = global i32 0
@cur_token = global i32 0
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

define i32 @next_char() {
bb1:
  %r292 = call i32 @getch()
  store i32 %r292, ptr @last_char, align 4
  %r293 = load i32, ptr @last_char, align 4
  ret i32 %r293
}

define i32 @is_space(i32 %r102) {
bb2:
  %r294 = add i32 0, 0
  %r295 = add i32 %r102, 0
  %r296 = icmp eq i32 %r295, 32
  br i1 %r296, label %bb3, label %bb6

bb6:                                              ; preds = %bb2
  %r297 = icmp eq i32 %r295, 10
  br i1 %r297, label %bb3, label %bb4

bb3:                                              ; preds = %bb6, %bb2
  ret i32 1

bb4:                                              ; preds = %bb6
  ret i32 0
}

define i32 @is_num(i32 %r108) {
bb7:
  %r298 = add i32 0, 0
  %r299 = add i32 %r108, 0
  %r300 = icmp sge i32 %r299, 48
  br i1 %r300, label %bb11, label %bb9

bb11:                                             ; preds = %bb7
  %r301 = icmp sle i32 %r299, 57
  br i1 %r301, label %bb8, label %bb9

bb8:                                              ; preds = %bb11
  ret i32 1

bb9:                                              ; preds = %bb11, %bb7
  ret i32 0
}

define i32 @next_token() {
bb12:
  br label %bb13

bb13:                                             ; preds = %bb14, %bb12
  %r302 = load i32, ptr @last_char, align 4
  %r303 = call i32 @is_space(i32 %r302)
  %r304 = icmp ne i32 %r303, 0
  br i1 %r304, label %bb14, label %bb15

bb14:                                             ; preds = %bb13
  call void @next_char()
  br label %bb13

bb15:                                             ; preds = %bb13
  %r305 = load i32, ptr @last_char, align 4
  %r306 = call i32 @is_num(i32 %r305)
  %r307 = icmp ne i32 %r306, 0
  br i1 %r307, label %bb16, label %bb17

bb16:                                             ; preds = %bb15
  %r308 = load i32, ptr @last_char, align 4
  %r309 = sub i32 %r308, 48
  store i32 %r309, ptr @num, align 4
  br label %bb19

bb19:                                             ; preds = %bb20, %bb16
  %r310 = call i32 @next_char()
  %r311 = call i32 @is_num(i32 %r310)
  %r312 = icmp ne i32 %r311, 0
  br i1 %r312, label %bb20, label %bb21

bb20:                                             ; preds = %bb19
  %r313 = load i32, ptr @num, align 4
  %r314 = mul i32 %r313, 10
  %r315 = load i32, ptr @last_char, align 4
  %r316 = add i32 %r314, %r315
  %r317 = sub i32 %r316, 48
  store i32 %r317, ptr @num, align 4
  br label %bb19

bb21:                                             ; preds = %bb19
  %r318 = load i32, ptr @TOKEN_NUM, align 4
  store i32 %r318, ptr @cur_token, align 4
  br label %bb18

bb17:                                             ; preds = %bb15
  %r320 = load i32, ptr @last_char, align 4
  store i32 %r320, ptr @other, align 4
  call void @next_char()
  %r321 = load i32, ptr @TOKEN_OTHER, align 4
  store i32 %r321, ptr @cur_token, align 4
  br label %bb18

bb18:                                             ; preds = %bb17, %bb21
  %r319 = load i32, ptr @cur_token, align 4
  ret i32 %r319
}

define i32 @panic() {
bb22:
  call void @putch(i32 112)
  call void @putch(i32 97)
  call void @putch(i32 110)
  call void @putch(i32 105)
  call void @putch(i32 99)
  call void @putch(i32 33)
  call void @putch(i32 10)
  %r322 = sub i32 0, 1
  ret i32 %r322
}

define i32 @get_op_prec(i32 %r135) {
bb23:
  %r323 = add i32 0, 0
  %r324 = add i32 %r135, 0
  %r325 = icmp eq i32 %r324, 43
  br i1 %r325, label %bb24, label %bb27

bb27:                                             ; preds = %bb23
  %r326 = icmp eq i32 %r324, 45
  br i1 %r326, label %bb24, label %bb25

bb24:                                             ; preds = %bb27, %bb23
  ret i32 10

bb25:                                             ; preds = %bb27
  br label %bb26

bb26:                                             ; preds = %bb25
  %r327 = icmp eq i32 %r324, 42
  br i1 %r327, label %bb28, label %bb31

bb31:                                             ; preds = %bb26
  %r328 = icmp eq i32 %r324, 47
  br i1 %r328, label %bb28, label %bb32

bb32:                                             ; preds = %bb31
  %r329 = icmp eq i32 %r324, 37
  br i1 %r329, label %bb28, label %bb29

bb28:                                             ; preds = %bb32, %bb31, %bb26
  ret i32 20

bb29:                                             ; preds = %bb32
  br label %bb30

bb30:                                             ; preds = %bb29
  ret i32 0
}

define void @stack_push(ptr %r147, i32 %r148) {
bb33:
  %r330 = add i32 0, 0
  %r331 = add i32 %r148, 0
  %r150 = getelementptr i32, ptr %r147, i32 0
  %r332 = load i32, ptr %r150, align 4
  %r333 = add i32 %r332, 1
  %r153 = getelementptr i32, ptr %r147, i32 0
  store i32 %r333, ptr %r153, align 4
  %r334 = add i32 0, 0
  %r155 = getelementptr i32, ptr %r147, i32 0
  %r335 = load i32, ptr %r155, align 4
  %r336 = add i32 %r335, 0
  %r159 = getelementptr i32, ptr %r147, i32 %r336
  store i32 %r331, ptr %r159, align 4
  ret void
}

define i32 @stack_pop(ptr %r160) {
bb34:
  %r337 = add i32 0, 0
  %r162 = getelementptr i32, ptr %r160, i32 0
  %r338 = load i32, ptr %r162, align 4
  %r339 = add i32 %r338, 0
  %r340 = add i32 0, 0
  %r166 = getelementptr i32, ptr %r160, i32 %r339
  %r341 = load i32, ptr %r166, align 4
  %r342 = add i32 %r341, 0
  %r168 = getelementptr i32, ptr %r160, i32 0
  %r343 = load i32, ptr %r168, align 4
  %r344 = sub i32 %r343, 1
  %r171 = getelementptr i32, ptr %r160, i32 0
  store i32 %r344, ptr %r171, align 4
  ret i32 %r342
}

define i32 @stack_peek(ptr %r173) {
bb35:
  %r345 = add i32 0, 0
  %r175 = getelementptr i32, ptr %r173, i32 0
  %r346 = load i32, ptr %r175, align 4
  %r347 = add i32 %r346, 0
  %r178 = getelementptr i32, ptr %r173, i32 %r347
  %r348 = load i32, ptr %r178, align 4
  ret i32 %r348
}

define i32 @stack_size(ptr %r180) {
bb36:
  %r181 = getelementptr i32, ptr %r180, i32 0
  %r349 = load i32, ptr %r181, align 4
  ret i32 %r349
}

define i32 @mod(i32 %r183, i32 %r185) {
bb37:
  %r350 = add i32 0, 0
  %r351 = add i32 %r183, 0
  %r352 = add i32 0, 0
  %r353 = add i32 %r185, 0
  %r354 = sdiv i32 %r351, %r353
  %r355 = mul i32 %r354, %r353
  %r356 = sub i32 %r351, %r355
  ret i32 %r356
}

define i32 @eval_op(i32 %r194, i32 %r196, i32 %r198) {
bb38:
  %r357 = add i32 0, 0
  %r358 = add i32 %r194, 0
  %r359 = add i32 0, 0
  %r360 = add i32 %r196, 0
  %r361 = add i32 0, 0
  %r362 = add i32 %r198, 0
  %r363 = icmp eq i32 %r358, 43
  br i1 %r363, label %bb39, label %bb40

bb39:                                             ; preds = %bb38
  %r364 = add i32 %r360, %r362
  ret i32 %r364

bb40:                                             ; preds = %bb38
  br label %bb41

bb41:                                             ; preds = %bb40
  %r365 = icmp eq i32 %r358, 45
  br i1 %r365, label %bb42, label %bb43

bb42:                                             ; preds = %bb41
  %r366 = sub i32 %r360, %r362
  ret i32 %r366

bb43:                                             ; preds = %bb41
  br label %bb44

bb44:                                             ; preds = %bb43
  %r367 = icmp eq i32 %r358, 42
  br i1 %r367, label %bb45, label %bb46

bb45:                                             ; preds = %bb44
  %r368 = mul i32 %r360, %r362
  ret i32 %r368

bb46:                                             ; preds = %bb44
  br label %bb47

bb47:                                             ; preds = %bb46
  %r369 = icmp eq i32 %r358, 47
  br i1 %r369, label %bb48, label %bb49

bb48:                                             ; preds = %bb47
  %r370 = sdiv i32 %r360, %r362
  ret i32 %r370

bb49:                                             ; preds = %bb47
  br label %bb50

bb50:                                             ; preds = %bb49
  %r371 = icmp eq i32 %r358, 37
  br i1 %r371, label %bb51, label %bb52

bb51:                                             ; preds = %bb50
  %r372 = call i32 @mod(i32 %r360, i32 %r362)
  ret i32 %r372

bb52:                                             ; preds = %bb50
  br label %bb53

bb53:                                             ; preds = %bb52
  ret i32 0
}

define i32 @eval() {
bb54:
  %r373 = add i32 0, 0
  %r374 = add i32 0, 0
  %r375 = add i32 0, 0
  %r376 = add i32 0, 0
  %r377 = add i32 0, 0
  %r378 = add i32 0, 0
  %r379 = add i32 0, 0
  %r225 = alloca [256 x i32], align 4
  %r226 = alloca [256 x i32], align 4
  %r380 = add i32 0, 0
  %r381 = add i32 0, 0
  br label %bb55

bb55:                                             ; preds = %bb56, %bb54
  %r382 = phi i32 [ %r381, %bb54 ], [ %r385, %bb56 ]
  %r383 = icmp slt i32 %r382, 256
  br i1 %r383, label %bb56, label %bb57

bb56:                                             ; preds = %bb55
  %r231 = getelementptr [256 x i32], ptr %r225, i32 0, i32 %r382
  store i32 0, ptr %r231, align 4
  %r233 = getelementptr [256 x i32], ptr %r226, i32 0, i32 %r382
  store i32 0, ptr %r233, align 4
  %r384 = add i32 %r382, 1
  %r385 = add i32 %r384, 0
  br label %bb55

bb57:                                             ; preds = %bb55
  %r386 = load i32, ptr @cur_token, align 4
  %r387 = load i32, ptr @TOKEN_NUM, align 4
  %r388 = icmp ne i32 %r386, %r387
  br i1 %r388, label %bb58, label %bb59

bb58:                                             ; preds = %bb57
  %r389 = call i32 @panic()
  ret i32 %r389

bb59:                                             ; preds = %bb57
  br label %bb60

bb60:                                             ; preds = %bb59
  %r390 = load i32, ptr @num, align 4
  call void @stack_push(ptr %r225, i32 %r390)
  call void @next_token()
  br label %bb61

bb61:                                             ; preds = %bb73, %bb60
  %r391 = load i32, ptr @cur_token, align 4
  %r392 = load i32, ptr @TOKEN_OTHER, align 4
  %r393 = icmp eq i32 %r391, %r392
  br i1 %r393, label %bb62, label %bb63

bb62:                                             ; preds = %bb61
  %r394 = load i32, ptr @other, align 4
  %r395 = add i32 %r394, 0
  %r396 = call i32 @get_op_prec(i32 %r395)
  %r397 = icmp eq i32 %r396, 0
  br i1 %r397, label %bb64, label %bb65

bb64:                                             ; preds = %bb62
  br label %bb63

bb65:                                             ; preds = %bb62
  br label %bb66

bb66:                                             ; preds = %bb65
  call void @next_token()
  br label %bb67

bb67:                                             ; preds = %bb68, %bb66
  %r408 = call i32 @stack_size(ptr %r226)
  %r409 = icmp ne i32 %r408, 0
  br i1 %r409, label %bb70, label %bb69

bb70:                                             ; preds = %bb67
  %r410 = call i32 @stack_peek(ptr %r226)
  %r411 = call i32 @get_op_prec(i32 %r410)
  %r412 = call i32 @get_op_prec(i32 %r395)
  %r413 = icmp sge i32 %r411, %r412
  br i1 %r413, label %bb68, label %bb69

bb68:                                             ; preds = %bb70
  %r414 = call i32 @stack_pop(ptr %r226)
  %r415 = add i32 %r414, 0
  %r416 = call i32 @stack_pop(ptr %r225)
  %r417 = add i32 %r416, 0
  %r418 = call i32 @stack_pop(ptr %r225)
  %r419 = add i32 %r418, 0
  %r420 = call i32 @eval_op(i32 %r415, i32 %r419, i32 %r417)
  call void @stack_push(ptr %r225, i32 %r420)
  br label %bb67

bb69:                                             ; preds = %bb70, %bb67
  call void @stack_push(ptr %r226, i32 %r395)
  %r421 = load i32, ptr @cur_token, align 4
  %r422 = load i32, ptr @TOKEN_NUM, align 4
  %r423 = icmp ne i32 %r421, %r422
  br i1 %r423, label %bb71, label %bb72

bb71:                                             ; preds = %bb69
  %r424 = call i32 @panic()
  ret i32 %r424

bb72:                                             ; preds = %bb69
  br label %bb73

bb73:                                             ; preds = %bb72
  %r425 = load i32, ptr @num, align 4
  call void @stack_push(ptr %r225, i32 %r425)
  call void @next_token()
  br label %bb61

bb63:                                             ; preds = %bb64, %bb61
  call void @next_token()
  br label %bb74

bb74:                                             ; preds = %bb75, %bb63
  %r398 = call i32 @stack_size(ptr %r226)
  %r399 = icmp ne i32 %r398, 0
  br i1 %r399, label %bb75, label %bb76

bb75:                                             ; preds = %bb74
  %r400 = call i32 @stack_pop(ptr %r226)
  %r401 = add i32 %r400, 0
  %r402 = call i32 @stack_pop(ptr %r225)
  %r403 = add i32 %r402, 0
  %r404 = call i32 @stack_pop(ptr %r225)
  %r405 = add i32 %r404, 0
  %r406 = call i32 @eval_op(i32 %r401, i32 %r405, i32 %r403)
  call void @stack_push(ptr %r225, i32 %r406)
  br label %bb74

bb76:                                             ; preds = %bb74
  %r407 = call i32 @stack_peek(ptr %r225)
  ret i32 %r407
}

define i32 @main() {
bb77:
  call void @_sysy_starttime(i32 205)
  %r426 = add i32 0, 0
  %r427 = call i32 @getint()
  %r428 = add i32 %r427, 0
  call void @getch()
  call void @next_token()
  br label %bb78

bb78:                                             ; preds = %bb79, %bb77
  %r429 = phi i32 [ %r428, %bb77 ], [ %r433, %bb79 ]
  %r430 = icmp ne i32 %r429, 0
  br i1 %r430, label %bb79, label %bb80

bb79:                                             ; preds = %bb78
  %r431 = call i32 @eval()
  call void @putint(i32 %r431)
  call void @putch(i32 10)
  %r432 = sub i32 %r429, 1
  %r433 = add i32 %r432, 0
  br label %bb78

bb80:                                             ; preds = %bb78
  call void @_sysy_stoptime(i32 214)
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
