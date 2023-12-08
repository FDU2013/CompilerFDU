declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@INF = global i32 65535
%array2D = type { [16 x i32 ] }
@e = global [ 16 x %array2D ] zeroinitializer
@book = global [ 16 x i32 ] zeroinitializer
@dis = global [ 16 x i32 ] zeroinitializer
@n = global i32 0
@m = global i32 0
@v1 = global i32 0
@v2 = global i32 0
@w = global i32 0
define void @Dijkstra( ) {
bb1:
  %r237 = add i32 0, 0
  %r238 = add i32 0, 0
  %r239 = add i32 0, 0
  %r240 = add i32 0, 0
  %r241 = add i32 0, 0
  %r242 = add i32 1, 0
  br label %bb2

bb2:
  %r243 = phi i32 [ %r242, %bb1 ], [ %r248, %bb3 ]
  %r244 = load i32, i32* @n
  %r245 = icmp sle i32 %r243, %r244
  br i1 %r245, label %bb3, label %bb4

bb3:
  %r104 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 1
  %r105 = getelementptr %array2D, %array2D* %r104, i32 0, i32 0
  %r107 = getelementptr [16 x i32 ], [16 x i32 ]* %r105, i32 0, i32 %r243
  %r246 = load i32, i32* %r107
  %r110 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r243
  store i32 %r246, i32* %r110
  %r112 = getelementptr [16 x i32 ], [16 x i32 ]* @book, i32 0, i32 %r243
  store i32 0, i32* %r112
  %r247 = add i32 %r243, 1
  %r248 = add i32 %r247, 0
  br label %bb2

bb4:
  %r115 = getelementptr [16 x i32 ], [16 x i32 ]* @book, i32 0, i32 1
  store i32 1, i32* %r115
  %r249 = add i32 1, 0
  br label %bb5

bb5:
  %r250 = phi i32 [ %r249, %bb4 ], [ %r292, %bb17 ]
  %r251 = load i32, i32* @n
  %r252 = sub i32 %r251, 1
  %r253 = icmp sle i32 %r250, %r252
  br i1 %r253, label %bb6, label %bb7

bb6:
  %r254 = load i32, i32* @INF
  %r255 = add i32 %r254, 0
  %r256 = add i32 0, 0
  %r257 = add i32 1, 0
  br label %bb8

bb8:
  %r258 = phi i32 [ %r256, %bb6 ], [ %r270, %bb13 ]
  %r259 = phi i32 [ %r257, %bb6 ], [ %r273, %bb13 ]
  %r260 = phi i32 [ %r255, %bb6 ], [ %r271, %bb13 ]
  %r261 = load i32, i32* @n
  %r262 = icmp sle i32 %r259, %r261
  br i1 %r262, label %bb9, label %bb10

bb9:
  %r129 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r259
  %r263 = load i32, i32* %r129
  %r264 = icmp sgt i32 %r260, %r263
  br i1 %r264, label %bb14, label %bb12

bb14:
  %r133 = getelementptr [16 x i32 ], [16 x i32 ]* @book, i32 0, i32 %r259
  %r265 = load i32, i32* %r133
  %r266 = icmp eq i32 %r265, 0
  br i1 %r266, label %bb11, label %bb12

bb11:
  %r137 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r259
  %r267 = load i32, i32* %r137
  %r268 = add i32 %r267, 0
  %r269 = add i32 %r259, 0
  br label %bb13

bb12:
  br label %bb13

bb13:
  %r270 = phi i32 [ %r269, %bb11 ], [ %r258, %bb12 ]
  %r271 = phi i32 [ %r268, %bb11 ], [ %r260, %bb12 ]
  %r272 = add i32 %r259, 1
  %r273 = add i32 %r272, 0
  br label %bb8

bb10:
  %r143 = getelementptr [16 x i32 ], [16 x i32 ]* @book, i32 0, i32 %r258
  store i32 1, i32* %r143
  %r274 = add i32 1, 0
  br label %bb15

bb15:
  %r275 = phi i32 [ %r274, %bb10 ], [ %r290, %bb20 ]
  %r276 = load i32, i32* @n
  %r277 = icmp sle i32 %r275, %r276
  br i1 %r277, label %bb16, label %bb17

bb16:
  %r149 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r258
  %r150 = getelementptr %array2D, %array2D* %r149, i32 0, i32 0
  %r152 = getelementptr [16 x i32 ], [16 x i32 ]* %r150, i32 0, i32 %r275
  %r278 = load i32, i32* %r152
  %r279 = load i32, i32* @INF
  %r280 = icmp slt i32 %r278, %r279
  br i1 %r280, label %bb18, label %bb19

bb18:
  %r157 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r275
  %r281 = load i32, i32* %r157
  %r160 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r258
  %r282 = load i32, i32* %r160
  %r163 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r258
  %r164 = getelementptr %array2D, %array2D* %r163, i32 0, i32 0
  %r166 = getelementptr [16 x i32 ], [16 x i32 ]* %r164, i32 0, i32 %r275
  %r283 = load i32, i32* %r166
  %r284 = add i32 %r282, %r283
  %r285 = icmp sgt i32 %r281, %r284
  br i1 %r285, label %bb21, label %bb22

bb21:
  %r171 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r258
  %r286 = load i32, i32* %r171
  %r174 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r258
  %r175 = getelementptr %array2D, %array2D* %r174, i32 0, i32 0
  %r177 = getelementptr [16 x i32 ], [16 x i32 ]* %r175, i32 0, i32 %r275
  %r287 = load i32, i32* %r177
  %r288 = add i32 %r286, %r287
  %r181 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r275
  store i32 %r288, i32* %r181
  br label %bb23

bb22:
  br label %bb23

bb23:
  br label %bb20

bb19:
  br label %bb20

bb20:
  %r289 = add i32 %r275, 1
  %r290 = add i32 %r289, 0
  br label %bb15

bb17:
  %r291 = add i32 %r250, 1
  %r292 = add i32 %r291, 0
  br label %bb5

bb7:
  ret void
}

define i32 @main( ) {
bb24:
  %r293 = add i32 0, 0
  %r294 = add i32 0, 0
  %r295 = add i32 0, 0
  call void @_sysy_starttime(i32 53)
  %r296 = add i32 0, 0
  %r297 = call i32 @getint()
  store i32 %r297, i32* @n
  %r298 = call i32 @getint()
  store i32 %r298, i32* @m
  %r299 = add i32 1, 0
  br label %bb25

bb25:
  %r300 = phi i32 [ %r299, %bb24 ], [ %r312, %bb30 ]
  %r301 = load i32, i32* @n
  %r302 = icmp sle i32 %r300, %r301
  br i1 %r302, label %bb26, label %bb27

bb26:
  %r303 = add i32 1, 0
  br label %bb28

bb28:
  %r304 = phi i32 [ %r303, %bb26 ], [ %r309, %bb33 ]
  %r305 = load i32, i32* @n
  %r306 = icmp sle i32 %r304, %r305
  br i1 %r306, label %bb29, label %bb30

bb29:
  %r307 = icmp eq i32 %r300, %r304
  br i1 %r307, label %bb31, label %bb32

bb31:
  %r200 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r300
  %r201 = getelementptr %array2D, %array2D* %r200, i32 0, i32 0
  %r203 = getelementptr [16 x i32 ], [16 x i32 ]* %r201, i32 0, i32 %r304
  store i32 0, i32* %r203
  br label %bb33

bb32:
  %r310 = load i32, i32* @INF
  %r206 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r300
  %r207 = getelementptr %array2D, %array2D* %r206, i32 0, i32 0
  %r209 = getelementptr [16 x i32 ], [16 x i32 ]* %r207, i32 0, i32 %r304
  store i32 %r310, i32* %r209
  br label %bb33

bb33:
  %r308 = add i32 %r304, 1
  %r309 = add i32 %r308, 0
  br label %bb28

bb30:
  %r311 = add i32 %r300, 1
  %r312 = add i32 %r311, 0
  br label %bb25

bb27:
  %r313 = add i32 1, 0
  br label %bb34

bb34:
  %r314 = phi i32 [ %r313, %bb27 ], [ %r323, %bb35 ]
  %r315 = load i32, i32* @m
  %r316 = icmp sle i32 %r314, %r315
  br i1 %r316, label %bb35, label %bb36

bb35:
  %r317 = call i32 @getint()
  %r318 = add i32 %r317, 0
  %r319 = call i32 @getint()
  %r320 = add i32 %r319, 0
  %r321 = call i32 @getint()
  %r223 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r318
  %r224 = getelementptr %array2D, %array2D* %r223, i32 0, i32 0
  %r226 = getelementptr [16 x i32 ], [16 x i32 ]* %r224, i32 0, i32 %r320
  store i32 %r321, i32* %r226
  %r322 = add i32 %r314, 1
  %r323 = add i32 %r322, 0
  br label %bb34

bb36:
  call void @Dijkstra()
  %r324 = add i32 1, 0
  br label %bb37

bb37:
  %r325 = phi i32 [ %r324, %bb36 ], [ %r330, %bb38 ]
  %r326 = load i32, i32* @n
  %r327 = icmp sle i32 %r325, %r326
  br i1 %r327, label %bb38, label %bb39

bb38:
  %r233 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r325
  %r328 = load i32, i32* %r233
  call void @putint(i32 %r328)
  call void @putch(i32 32)
  %r329 = add i32 %r325, 1
  %r330 = add i32 %r329, 0
  br label %bb37

bb39:
  call void @putch(i32 10)
  call void @_sysy_stoptime(i32 91)
  ret i32 0
}

