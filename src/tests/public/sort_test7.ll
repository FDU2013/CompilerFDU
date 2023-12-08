declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@n = global i32 0
define i32 @Merge( i32* %r100, i32 %r101, i32 %r103, i32 %r105 ) {
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
  %r116 = alloca [ 10 x i32 ]
  %r117 = alloca [ 10 x i32 ]
  %r274 = add i32 0, 0
  %r275 = add i32 0, 0
  %r276 = add i32 0, 0
  %r277 = add i32 0, 0
  %r278 = add i32 0, 0
  br label %bb2

bb2:
  %r279 = phi i32 [ %r275, %bb1 ], [ %r285, %bb3 ]
  %r280 = icmp slt i32 %r279, %r270
  br i1 %r280, label %bb3, label %bb4

bb3:
  %r281 = add i32 %r279, %r262
  %r282 = add i32 %r281, 0
  %r128 = getelementptr i32, i32* %r100, i32 %r282
  %r283 = load i32, i32* %r128
  %r131 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r279
  store i32 %r283, i32* %r131
  %r284 = add i32 %r279, 1
  %r285 = add i32 %r284, 0
  br label %bb2

bb4:
  br label %bb5

bb5:
  %r286 = phi i32 [ %r277, %bb4 ], [ %r293, %bb6 ]
  %r287 = icmp slt i32 %r286, %r273
  br i1 %r287, label %bb6, label %bb7

bb6:
  %r288 = add i32 %r286, %r264
  %r289 = add i32 %r288, 1
  %r290 = add i32 %r289, 0
  %r142 = getelementptr i32, i32* %r100, i32 %r290
  %r291 = load i32, i32* %r142
  %r145 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r286
  store i32 %r291, i32* %r145
  %r292 = add i32 %r286, 1
  %r293 = add i32 %r292, 0
  br label %bb5

bb7:
  %r294 = add i32 0, 0
  %r295 = add i32 0, 0
  %r296 = add i32 %r262, 0
  br label %bb8

bb8:
  %r297 = phi i32 [ %r294, %bb7 ], [ %r311, %bb14 ]
  %r298 = phi i32 [ %r296, %bb7 ], [ %r312, %bb14 ]
  %r299 = phi i32 [ %r295, %bb7 ], [ %r313, %bb14 ]
  %r300 = icmp ne i32 %r297, %r270
  br i1 %r300, label %bb11, label %bb10

bb11:
  %r301 = icmp ne i32 %r299, %r273
  br i1 %r301, label %bb9, label %bb10

bb9:
  %r157 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r297
  %r302 = load i32, i32* %r157
  %r160 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r299
  %r303 = load i32, i32* %r160
  %r304 = add i32 %r303, 1
  %r305 = icmp slt i32 %r302, %r304
  br i1 %r305, label %bb12, label %bb13

bb12:
  %r165 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r297
  %r306 = load i32, i32* %r165
  %r168 = getelementptr i32, i32* %r100, i32 %r298
  store i32 %r306, i32* %r168
  %r307 = add i32 %r298, 1
  %r308 = add i32 %r307, 0
  %r309 = add i32 %r297, 1
  %r310 = add i32 %r309, 0
  br label %bb14

bb13:
  %r174 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r299
  %r314 = load i32, i32* %r174
  %r177 = getelementptr i32, i32* %r100, i32 %r298
  store i32 %r314, i32* %r177
  %r315 = add i32 %r298, 1
  %r316 = add i32 %r315, 0
  %r317 = add i32 %r299, 1
  %r318 = add i32 %r317, 0
  br label %bb14

bb14:
  %r311 = phi i32 [ %r310, %bb12 ], [ %r297, %bb13 ]
  %r312 = phi i32 [ %r308, %bb12 ], [ %r316, %bb13 ]
  %r313 = phi i32 [ %r299, %bb12 ], [ %r318, %bb13 ]
  br label %bb8

bb10:
  br label %bb15

bb15:
  %r319 = phi i32 [ %r297, %bb10 ], [ %r326, %bb16 ]
  %r320 = phi i32 [ %r298, %bb10 ], [ %r324, %bb16 ]
  %r321 = icmp slt i32 %r319, %r270
  br i1 %r321, label %bb16, label %bb17

bb16:
  %r186 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r319
  %r322 = load i32, i32* %r186
  %r189 = getelementptr i32, i32* %r100, i32 %r320
  store i32 %r322, i32* %r189
  %r323 = add i32 %r320, 1
  %r324 = add i32 %r323, 0
  %r325 = add i32 %r319, 1
  %r326 = add i32 %r325, 0
  br label %bb15

bb17:
  br label %bb18

bb18:
  %r327 = phi i32 [ %r320, %bb17 ], [ %r332, %bb19 ]
  %r328 = phi i32 [ %r299, %bb17 ], [ %r334, %bb19 ]
  %r329 = icmp slt i32 %r328, %r273
  br i1 %r329, label %bb19, label %bb20

bb19:
  %r198 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r328
  %r330 = load i32, i32* %r198
  %r201 = getelementptr i32, i32* %r100, i32 %r327
  store i32 %r330, i32* %r201
  %r331 = add i32 %r327, 1
  %r332 = add i32 %r331, 0
  %r333 = add i32 %r328, 1
  %r334 = add i32 %r333, 0
  br label %bb18

bb20:
  ret i32 0
}

define i32 @MergeSort( i32* %r206, i32 %r207, i32 %r209 ) {
bb21:
  %r335 = add i32 0, 0
  %r336 = add i32 0, 0
  %r337 = add i32 0, 0
  %r338 = add i32 %r207, 0
  %r339 = add i32 0, 0
  %r340 = add i32 %r209, 0
  %r341 = icmp slt i32 %r338, %r340
  br i1 %r341, label %bb22, label %bb23

bb22:
  %r342 = add i32 %r338, %r340
  %r343 = sdiv i32 %r342, 2
  %r344 = add i32 %r343, 0
  %r345 = call i32 @MergeSort(i32* %r206, i32 %r338, i32 %r344)
  %r346 = add i32 %r345, 0
  %r347 = add i32 %r344, 1
  %r348 = add i32 %r347, 0
  %r349 = call i32 @MergeSort(i32* %r206, i32 %r348, i32 %r340)
  %r350 = add i32 %r349, 0
  %r351 = call i32 @Merge(i32* %r206, i32 %r338, i32 %r344, i32 %r340)
  %r352 = add i32 %r351, 0
  br label %bb24

bb23:
  br label %bb24

bb24:
  ret i32 0
}

define i32 @main( ) {
bb25:
  call void @_sysy_starttime(i32 71)
  store i32 10, i32* @n
  %r232 = alloca [ 10 x i32 ]
  %r233 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 0
  store i32 4, i32* %r233
  %r234 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 1
  store i32 3, i32* %r234
  %r235 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 2
  store i32 9, i32* %r235
  %r236 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 3
  store i32 2, i32* %r236
  %r237 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 4
  store i32 0, i32* %r237
  %r238 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 5
  store i32 1, i32* %r238
  %r239 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 6
  store i32 6, i32* %r239
  %r240 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 7
  store i32 5, i32* %r240
  %r241 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 8
  store i32 7, i32* %r241
  %r242 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 9
  store i32 8, i32* %r242
  %r353 = add i32 0, 0
  %r354 = add i32 0, 0
  %r355 = add i32 0, 0
  %r356 = load i32, i32* @n
  %r357 = sub i32 %r356, 1
  %r358 = add i32 %r357, 0
  %r359 = call i32 @MergeSort(i32* %r232, i32 %r354, i32 %r358)
  %r360 = add i32 %r359, 0
  br label %bb26

bb26:
  %r361 = phi i32 [ %r360, %bb25 ], [ %r368, %bb27 ]
  %r362 = load i32, i32* @n
  %r363 = icmp slt i32 %r361, %r362
  br i1 %r363, label %bb27, label %bb28

bb27:
  %r254 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 %r361
  %r364 = load i32, i32* %r254
  %r365 = add i32 %r364, 0
  call void @putint(i32 %r365)
  %r366 = add i32 10, 0
  call void @putch(i32 %r366)
  %r367 = add i32 %r361, 1
  %r368 = add i32 %r367, 0
  br label %bb26

bb28:
  call void @_sysy_stoptime(i32 97)
  ret i32 0
}

