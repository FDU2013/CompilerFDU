declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@TOKEN_NUM = global i32 0
@TOKEN_OTHER = global i32 1
@last_char = global i32 32
@num = global i32 0
@other = global i32 0
@cur_token = global i32 0
define i32 @next_char( ) {
bb1:
  %r292 = call i32 @getch()
  store i32 %r292, i32* @last_char
  %r293 = load i32, i32* @last_char
  ret i32 %r293
}

define i32 @is_space( i32 %r102 ) {
bb2:
  %r294 = add i32 0, 0
  %r295 = add i32 %r102, 0
  %r296 = icmp eq i32 %r295, 32
  br i1 %r296, label %bb3, label %bb6

bb6:
  %r297 = icmp eq i32 %r295, 10
  br i1 %r297, label %bb3, label %bb4

bb3:
  ret i32 1
bb4:
  ret i32 0
}

define i32 @is_num( i32 %r108 ) {
bb7:
  %r298 = add i32 0, 0
  %r299 = add i32 %r108, 0
  %r300 = icmp sge i32 %r299, 48
  br i1 %r300, label %bb11, label %bb9

bb11:
  %r301 = icmp sle i32 %r299, 57
  br i1 %r301, label %bb8, label %bb9

bb8:
  ret i32 1
bb9:
  ret i32 0
}

define i32 @next_token( ) {
bb12:
  br label %bb13

bb13:
  %r302 = load i32, i32* @last_char
  %r303 = call i32 @is_space(i32 %r302)
  %r304 = icmp ne i32 %r303, 0
  br i1 %r304, label %bb14, label %bb15

bb14:
  call void @next_char()
  br label %bb13

bb15:
  %r305 = load i32, i32* @last_char
  %r306 = call i32 @is_num(i32 %r305)
  %r307 = icmp ne i32 %r306, 0
  br i1 %r307, label %bb16, label %bb17

bb16:
  %r308 = load i32, i32* @last_char
  %r309 = sub i32 %r308, 48
  store i32 %r309, i32* @num
  br label %bb19

bb19:
  %r310 = call i32 @next_char()
  %r311 = call i32 @is_num(i32 %r310)
  %r312 = icmp ne i32 %r311, 0
  br i1 %r312, label %bb20, label %bb21

bb20:
  %r313 = load i32, i32* @num
  %r314 = mul i32 %r313, 10
  %r315 = load i32, i32* @last_char
  %r316 = add i32 %r314, %r315
  %r317 = sub i32 %r316, 48
  store i32 %r317, i32* @num
  br label %bb19

bb21:
  %r318 = load i32, i32* @TOKEN_NUM
  store i32 %r318, i32* @cur_token
  br label %bb18

bb17:
  %r320 = load i32, i32* @last_char
  store i32 %r320, i32* @other
  call void @next_char()
  %r321 = load i32, i32* @TOKEN_OTHER
  store i32 %r321, i32* @cur_token
  br label %bb18

bb18:
  %r319 = load i32, i32* @cur_token
  ret i32 %r319
}

define i32 @panic( ) {
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

define i32 @get_op_prec( i32 %r135 ) {
bb23:
  %r323 = add i32 0, 0
  %r324 = add i32 %r135, 0
  %r325 = icmp eq i32 %r324, 43
  br i1 %r325, label %bb24, label %bb27

bb27:
  %r326 = icmp eq i32 %r324, 45
  br i1 %r326, label %bb24, label %bb25

bb24:
  ret i32 10
bb25:
  br label %bb26

bb26:
  %r327 = icmp eq i32 %r324, 42
  br i1 %r327, label %bb28, label %bb31

bb31:
  %r328 = icmp eq i32 %r324, 47
  br i1 %r328, label %bb28, label %bb32

bb32:
  %r329 = icmp eq i32 %r324, 37
  br i1 %r329, label %bb28, label %bb29

bb28:
  ret i32 20
bb29:
  br label %bb30

bb30:
  ret i32 0
}

define void @stack_push( i32* %r147, i32 %r148 ) {
bb33:
  %r330 = add i32 0, 0
  %r331 = add i32 %r148, 0
  %r150 = getelementptr i32, i32* %r147, i32 0
  %r332 = load i32, i32* %r150
  %r333 = add i32 %r332, 1
  %r153 = getelementptr i32, i32* %r147, i32 0
  store i32 %r333, i32* %r153
  %r334 = add i32 0, 0
  %r155 = getelementptr i32, i32* %r147, i32 0
  %r335 = load i32, i32* %r155
  %r336 = add i32 %r335, 0
  %r159 = getelementptr i32, i32* %r147, i32 %r336
  store i32 %r331, i32* %r159
  ret void
}

define i32 @stack_pop( i32* %r160 ) {
bb34:
  %r337 = add i32 0, 0
  %r162 = getelementptr i32, i32* %r160, i32 0
  %r338 = load i32, i32* %r162
  %r339 = add i32 %r338, 0
  %r340 = add i32 0, 0
  %r166 = getelementptr i32, i32* %r160, i32 %r339
  %r341 = load i32, i32* %r166
  %r342 = add i32 %r341, 0
  %r168 = getelementptr i32, i32* %r160, i32 0
  %r343 = load i32, i32* %r168
  %r344 = sub i32 %r343, 1
  %r171 = getelementptr i32, i32* %r160, i32 0
  store i32 %r344, i32* %r171
  ret i32 %r342
}

define i32 @stack_peek( i32* %r173 ) {
bb35:
  %r345 = add i32 0, 0
  %r175 = getelementptr i32, i32* %r173, i32 0
  %r346 = load i32, i32* %r175
  %r347 = add i32 %r346, 0
  %r178 = getelementptr i32, i32* %r173, i32 %r347
  %r348 = load i32, i32* %r178
  ret i32 %r348
}

define i32 @stack_size( i32* %r180 ) {
bb36:
  %r181 = getelementptr i32, i32* %r180, i32 0
  %r349 = load i32, i32* %r181
  ret i32 %r349
}

define i32 @mod( i32 %r183, i32 %r185 ) {
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

define i32 @eval_op( i32 %r194, i32 %r196, i32 %r198 ) {
bb38:
  %r357 = add i32 0, 0
  %r358 = add i32 %r194, 0
  %r359 = add i32 0, 0
  %r360 = add i32 %r196, 0
  %r361 = add i32 0, 0
  %r362 = add i32 %r198, 0
  %r363 = icmp eq i32 %r358, 43
  br i1 %r363, label %bb39, label %bb40

bb39:
  %r364 = add i32 %r360, %r362
  ret i32 %r364
bb40:
  br label %bb41

bb41:
  %r365 = icmp eq i32 %r358, 45
  br i1 %r365, label %bb42, label %bb43

bb42:
  %r366 = sub i32 %r360, %r362
  ret i32 %r366
bb43:
  br label %bb44

bb44:
  %r367 = icmp eq i32 %r358, 42
  br i1 %r367, label %bb45, label %bb46

bb45:
  %r368 = mul i32 %r360, %r362
  ret i32 %r368
bb46:
  br label %bb47

bb47:
  %r369 = icmp eq i32 %r358, 47
  br i1 %r369, label %bb48, label %bb49

bb48:
  %r370 = sdiv i32 %r360, %r362
  ret i32 %r370
bb49:
  br label %bb50

bb50:
  %r371 = icmp eq i32 %r358, 37
  br i1 %r371, label %bb51, label %bb52

bb51:
  %r372 = call i32 @mod(i32 %r360, i32 %r362)
  ret i32 %r372
bb52:
  br label %bb53

bb53:
  ret i32 0
}

define i32 @eval( ) {
bb54:
  %r373 = add i32 0, 0
  %r374 = add i32 0, 0
  %r375 = add i32 0, 0
  %r376 = add i32 0, 0
  %r377 = add i32 0, 0
  %r378 = add i32 0, 0
  %r379 = add i32 0, 0
  %r225 = alloca [ 256 x i32 ]
  %r226 = alloca [ 256 x i32 ]
  %r380 = add i32 0, 0
  %r381 = add i32 0, 0
  br label %bb55

bb55:
  %r382 = phi i32 [ %r381, %bb54 ], [ %r385, %bb56 ]
  %r383 = icmp slt i32 %r382, 256
  br i1 %r383, label %bb56, label %bb57

bb56:
  %r231 = getelementptr [256 x i32 ], [256 x i32 ]* %r225, i32 0, i32 %r382
  store i32 0, i32* %r231
  %r233 = getelementptr [256 x i32 ], [256 x i32 ]* %r226, i32 0, i32 %r382
  store i32 0, i32* %r233
  %r384 = add i32 %r382, 1
  %r385 = add i32 %r384, 0
  br label %bb55

bb57:
  %r386 = load i32, i32* @cur_token
  %r387 = load i32, i32* @TOKEN_NUM
  %r388 = icmp ne i32 %r386, %r387
  br i1 %r388, label %bb58, label %bb59

bb58:
  %r389 = call i32 @panic()
  ret i32 %r389
bb59:
  br label %bb60

bb60:
  %r390 = load i32, i32* @num
  call void @stack_push(i32* %r225, i32 %r390)
  call void @next_token()
  br label %bb61

bb61:
  %r391 = load i32, i32* @cur_token
  %r392 = load i32, i32* @TOKEN_OTHER
  %r393 = icmp eq i32 %r391, %r392
  br i1 %r393, label %bb62, label %bb63

bb62:
  %r394 = load i32, i32* @other
  %r395 = add i32 %r394, 0
  %r396 = call i32 @get_op_prec(i32 %r395)
  %r397 = icmp eq i32 %r396, 0
  br i1 %r397, label %bb64, label %bb65

bb64:
  br label %bb63

bb65:
  br label %bb66

bb66:
  call void @next_token()
  br label %bb67

bb67:
  %r408 = call i32 @stack_size(i32* %r226)
  %r409 = icmp ne i32 %r408, 0
  br i1 %r409, label %bb70, label %bb69

bb70:
  %r410 = call i32 @stack_peek(i32* %r226)
  %r411 = call i32 @get_op_prec(i32 %r410)
  %r412 = call i32 @get_op_prec(i32 %r395)
  %r413 = icmp sge i32 %r411, %r412
  br i1 %r413, label %bb68, label %bb69

bb68:
  %r414 = call i32 @stack_pop(i32* %r226)
  %r415 = add i32 %r414, 0
  %r416 = call i32 @stack_pop(i32* %r225)
  %r417 = add i32 %r416, 0
  %r418 = call i32 @stack_pop(i32* %r225)
  %r419 = add i32 %r418, 0
  %r420 = call i32 @eval_op(i32 %r415, i32 %r419, i32 %r417)
  call void @stack_push(i32* %r225, i32 %r420)
  br label %bb67

bb69:
  call void @stack_push(i32* %r226, i32 %r395)
  %r421 = load i32, i32* @cur_token
  %r422 = load i32, i32* @TOKEN_NUM
  %r423 = icmp ne i32 %r421, %r422
  br i1 %r423, label %bb71, label %bb72

bb71:
  %r424 = call i32 @panic()
  ret i32 %r424
bb72:
  br label %bb73

bb73:
  %r425 = load i32, i32* @num
  call void @stack_push(i32* %r225, i32 %r425)
  call void @next_token()
  br label %bb61

bb63:
  call void @next_token()
  br label %bb74

bb74:
  %r398 = call i32 @stack_size(i32* %r226)
  %r399 = icmp ne i32 %r398, 0
  br i1 %r399, label %bb75, label %bb76

bb75:
  %r400 = call i32 @stack_pop(i32* %r226)
  %r401 = add i32 %r400, 0
  %r402 = call i32 @stack_pop(i32* %r225)
  %r403 = add i32 %r402, 0
  %r404 = call i32 @stack_pop(i32* %r225)
  %r405 = add i32 %r404, 0
  %r406 = call i32 @eval_op(i32 %r401, i32 %r405, i32 %r403)
  call void @stack_push(i32* %r225, i32 %r406)
  br label %bb74

bb76:
  %r407 = call i32 @stack_peek(i32* %r225)
  ret i32 %r407
}

define i32 @main( ) {
bb77:
  call void @_sysy_starttime(i32 205)
  %r426 = add i32 0, 0
  %r427 = call i32 @getint()
  %r428 = add i32 %r427, 0
  call void @getch()
  call void @next_token()
  br label %bb78

bb78:
  %r429 = phi i32 [ %r428, %bb77 ], [ %r433, %bb79 ]
  %r430 = icmp ne i32 %r429, 0
  br i1 %r430, label %bb79, label %bb80

bb79:
  %r431 = call i32 @eval()
  call void @putint(i32 %r431)
  call void @putch(i32 10)
  %r432 = sub i32 %r429, 1
  %r433 = add i32 %r432, 0
  br label %bb78

bb80:
  call void @_sysy_stoptime(i32 214)
  ret i32 0
}

