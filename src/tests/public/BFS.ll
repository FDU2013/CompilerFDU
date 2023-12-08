declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@n = global i32 0
@m = global i32 0
@to = global [ 5005 x i32 ] zeroinitializer
@next = global [ 5005 x i32 ] zeroinitializer
@head = global [ 1005 x i32 ] zeroinitializer
@cnt = global i32 0
@que = global [ 1005 x i32 ] zeroinitializer
@h = global i32 0
@tail = global i32 0
@inq = global [ 1005 x i32 ] zeroinitializer
define i32 @quickread( ) {
bb1:
  %r254 = add i32 0, 0
  %r255 = call i32 @getch()
  %r256 = add i32 %r255, 0
  %r257 = add i32 0, 0
  %r258 = add i32 0, 0
  %r259 = add i32 0, 0
  %r260 = add i32 0, 0
  br label %bb2

bb2:
  %r261 = phi i32 [ %r256, %bb1 ], [ %r269, %bb8 ]
  %r262 = phi i32 [ %r260, %bb1 ], [ %r267, %bb8 ]
  %r263 = icmp slt i32 %r261, 48
  br i1 %r263, label %bb3, label %bb5

bb5:
  %r264 = icmp sgt i32 %r261, 57
  br i1 %r264, label %bb3, label %bb4

bb3:
  %r265 = icmp eq i32 %r261, 45
  br i1 %r265, label %bb6, label %bb7

bb6:
  %r266 = add i32 1, 0
  br label %bb8

bb7:
  br label %bb8

bb8:
  %r267 = phi i32 [ %r266, %bb6 ], [ %r262, %bb7 ]
  %r268 = call i32 @getch()
  %r269 = add i32 %r268, 0
  br label %bb2

bb4:
  br label %bb9

bb9:
  %r270 = phi i32 [ %r261, %bb4 ], [ %r279, %bb10 ]
  %r271 = phi i32 [ %r258, %bb4 ], [ %r277, %bb10 ]
  %r272 = icmp sge i32 %r270, 48
  br i1 %r272, label %bb12, label %bb11

bb12:
  %r273 = icmp sle i32 %r270, 57
  br i1 %r273, label %bb10, label %bb11

bb10:
  %r274 = mul i32 %r271, 10
  %r275 = add i32 %r274, %r270
  %r276 = sub i32 %r275, 48
  %r277 = add i32 %r276, 0
  %r278 = call i32 @getch()
  %r279 = add i32 %r278, 0
  br label %bb9

bb11:
  %r280 = icmp ne i32 %r262, 0
  br i1 %r280, label %bb13, label %bb14

bb13:
  %r281 = sub i32 0, %r271
  ret i32 %r281
bb14:
  ret i32 %r271
}

define void @addedge( i32 %r126, i32 %r128 ) {
bb16:
  %r282 = add i32 0, 0
  %r283 = add i32 %r126, 0
  %r284 = add i32 0, 0
  %r285 = add i32 %r128, 0
  %r286 = load i32, i32* @cnt
  %r132 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r286
  store i32 %r285, i32* %r132
  %r134 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r283
  %r287 = load i32, i32* %r134
  %r288 = load i32, i32* @cnt
  %r137 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r288
  store i32 %r287, i32* %r137
  %r289 = load i32, i32* @cnt
  %r140 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r283
  store i32 %r289, i32* %r140
  %r290 = load i32, i32* @cnt
  %r291 = add i32 %r290, 1
  store i32 %r291, i32* @cnt
  %r292 = load i32, i32* @cnt
  %r145 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r292
  store i32 %r283, i32* %r145
  %r147 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r285
  %r293 = load i32, i32* %r147
  %r294 = load i32, i32* @cnt
  %r150 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r294
  store i32 %r293, i32* %r150
  %r295 = load i32, i32* @cnt
  %r153 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r285
  store i32 %r295, i32* %r153
  %r296 = load i32, i32* @cnt
  %r297 = add i32 %r296, 1
  store i32 %r297, i32* @cnt
  ret void
}

define void @init( ) {
bb17:
  %r298 = add i32 0, 0
  %r299 = add i32 0, 0
  br label %bb18

bb18:
  %r300 = phi i32 [ %r299, %bb17 ], [ %r304, %bb19 ]
  %r301 = icmp slt i32 %r300, 1005
  br i1 %r301, label %bb19, label %bb20

bb19:
  %r302 = sub i32 0, 1
  %r161 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r300
  store i32 %r302, i32* %r161
  %r303 = add i32 %r300, 1
  %r304 = add i32 %r303, 0
  br label %bb18

bb20:
  ret void
}

define void @inqueue( i32 %r164 ) {
bb21:
  %r305 = add i32 0, 0
  %r306 = add i32 %r164, 0
  %r167 = getelementptr [1005 x i32 ], [1005 x i32 ]* @inq, i32 0, i32 %r306
  store i32 1, i32* %r167
  %r307 = load i32, i32* @tail
  %r308 = add i32 %r307, 1
  store i32 %r308, i32* @tail
  %r309 = load i32, i32* @tail
  %r172 = getelementptr [1005 x i32 ], [1005 x i32 ]* @que, i32 0, i32 %r309
  store i32 %r306, i32* %r172
  ret void
}

define i32 @popqueue( ) {
bb22:
  %r310 = load i32, i32* @h
  %r311 = add i32 %r310, 1
  store i32 %r311, i32* @h
  %r312 = add i32 0, 0
  %r313 = load i32, i32* @h
  %r177 = getelementptr [1005 x i32 ], [1005 x i32 ]* @que, i32 0, i32 %r313
  %r314 = load i32, i32* %r177
  %r315 = add i32 %r314, 0
  %r316 = load i32, i32* @h
  %r180 = getelementptr [1005 x i32 ], [1005 x i32 ]* @que, i32 0, i32 %r316
  %r317 = load i32, i32* %r180
  ret i32 %r317
}

define i32 @same( i32 %r182, i32 %r184 ) {
bb23:
  %r318 = add i32 0, 0
  %r319 = add i32 %r182, 0
  %r320 = add i32 0, 0
  %r321 = add i32 %r184, 0
  store i32 0, i32* @h
  store i32 0, i32* @tail
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

bb24:
  %r330 = phi i32 [ %r323, %bb23 ], [ %r338, %bb32 ]
  %r331 = load i32, i32* @h
  %r332 = load i32, i32* @tail
  %r333 = icmp slt i32 %r331, %r332
  br i1 %r333, label %bb25, label %bb26

bb25:
  %r334 = call i32 @popqueue()
  %r335 = add i32 %r334, 0
  %r336 = icmp eq i32 %r335, %r321
  br i1 %r336, label %bb27, label %bb28

bb27:
  %r337 = add i32 1, 0
  br label %bb29

bb28:
  br label %bb29

bb29:
  %r338 = phi i32 [ %r337, %bb27 ], [ %r330, %bb28 ]
  %r199 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r335
  %r339 = load i32, i32* %r199
  %r340 = add i32 %r339, 0
  br label %bb30

bb30:
  %r341 = phi i32 [ %r340, %bb29 ], [ %r350, %bb35 ]
  %r342 = sub i32 0, 1
  %r343 = icmp ne i32 %r341, %r342
  br i1 %r343, label %bb31, label %bb32

bb31:
  %r205 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r341
  %r344 = load i32, i32* %r205
  %r345 = add i32 %r344, 0
  %r208 = getelementptr [1005 x i32 ], [1005 x i32 ]* @inq, i32 0, i32 %r345
  %r346 = load i32, i32* %r208
  %r347 = icmp eq i32 %r346, 0
  br i1 %r347, label %bb33, label %bb34

bb33:
  %r212 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r341
  %r348 = load i32, i32* %r212
  call void @inqueue(i32 %r348)
  br label %bb35

bb34:
  br label %bb35

bb35:
  %r215 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r341
  %r349 = load i32, i32* %r215
  %r350 = add i32 %r349, 0
  br label %bb30

bb32:
  br label %bb24

bb26:
  %r351 = add i32 0, 0
  br label %bb36

bb36:
  %r352 = phi i32 [ %r351, %bb26 ], [ %r358, %bb37 ]
  %r353 = load i32, i32* @tail
  %r354 = icmp sle i32 %r352, %r353
  br i1 %r354, label %bb37, label %bb38

bb37:
  %r221 = getelementptr [1005 x i32 ], [1005 x i32 ]* @que, i32 0, i32 %r352
  %r355 = load i32, i32* %r221
  %r356 = add i32 %r355, 0
  %r224 = getelementptr [1005 x i32 ], [1005 x i32 ]* @inq, i32 0, i32 %r356
  store i32 0, i32* %r224
  %r357 = add i32 %r352, 1
  %r358 = add i32 %r357, 0
  br label %bb36

bb38:
  ret i32 %r330
}

define i32 @main( ) {
bb39:
  %r359 = call i32 @quickread()
  store i32 %r359, i32* @n
  %r360 = call i32 @quickread()
  store i32 %r360, i32* @m
  call void @_sysy_starttime(i32 97)
  call void @init()
  %r361 = add i32 0, 0
  %r362 = add i32 0, 0
  %r363 = add i32 0, 0
  %r364 = add i32 0, 0
  %r365 = add i32 0, 0
  %r366 = add i32 0, 0
  br label %bb40

bb40:
  %r367 = load i32, i32* @m
  %r368 = icmp ne i32 %r367, 0
  br i1 %r368, label %bb41, label %bb42

bb41:
  %r369 = call i32 @getch()
  %r370 = add i32 %r369, 0
  br label %bb43

bb43:
  %r371 = phi i32 [ %r370, %bb41 ], [ %r375, %bb44 ]
  %r372 = icmp ne i32 %r371, 81
  br i1 %r372, label %bb46, label %bb45

bb46:
  %r373 = icmp ne i32 %r371, 85
  br i1 %r373, label %bb44, label %bb45

bb44:
  %r374 = call i32 @getch()
  %r375 = add i32 %r374, 0
  br label %bb43

bb45:
  %r376 = icmp eq i32 %r371, 81
  br i1 %r376, label %bb47, label %bb48

bb47:
  %r377 = call i32 @quickread()
  %r378 = add i32 %r377, 0
  %r379 = call i32 @quickread()
  %r380 = add i32 %r379, 0
  %r381 = call i32 @same(i32 %r378, i32 %r380)
  call void @putint(i32 %r381)
  call void @putch(i32 10)
  br label %bb49

bb48:
  %r384 = call i32 @quickread()
  %r385 = add i32 %r384, 0
  %r386 = call i32 @quickread()
  %r387 = add i32 %r386, 0
  call void @addedge(i32 %r385, i32 %r387)
  br label %bb49

bb49:
  %r382 = load i32, i32* @m
  %r383 = sub i32 %r382, 1
  store i32 %r383, i32* @m
  br label %bb40

bb42:
  call void @_sysy_stoptime(i32 117)
  ret i32 0
}

