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
@vis = global [ 1005 x i32 ] zeroinitializer
define i32 @quickread( ) {
bb1:
  %r229 = add i32 0, 0
  %r230 = call i32 @getch()
  %r231 = add i32 %r230, 0
  %r232 = add i32 0, 0
  %r233 = add i32 0, 0
  %r234 = add i32 0, 0
  %r235 = add i32 0, 0
  br label %bb2

bb2:
  %r236 = phi i32 [ %r231, %bb1 ], [ %r244, %bb8 ]
  %r237 = phi i32 [ %r235, %bb1 ], [ %r242, %bb8 ]
  %r238 = icmp slt i32 %r236, 48
  br i1 %r238, label %bb3, label %bb5

bb5:
  %r239 = icmp sgt i32 %r236, 57
  br i1 %r239, label %bb3, label %bb4

bb3:
  %r240 = icmp eq i32 %r236, 45
  br i1 %r240, label %bb6, label %bb7

bb6:
  %r241 = add i32 1, 0
  br label %bb8

bb7:
  br label %bb8

bb8:
  %r242 = phi i32 [ %r241, %bb6 ], [ %r237, %bb7 ]
  %r243 = call i32 @getch()
  %r244 = add i32 %r243, 0
  br label %bb2

bb4:
  br label %bb9

bb9:
  %r245 = phi i32 [ %r236, %bb4 ], [ %r254, %bb10 ]
  %r246 = phi i32 [ %r233, %bb4 ], [ %r252, %bb10 ]
  %r247 = icmp sge i32 %r245, 48
  br i1 %r247, label %bb12, label %bb11

bb12:
  %r248 = icmp sle i32 %r245, 57
  br i1 %r248, label %bb10, label %bb11

bb10:
  %r249 = mul i32 %r246, 10
  %r250 = add i32 %r249, %r245
  %r251 = sub i32 %r250, 48
  %r252 = add i32 %r251, 0
  %r253 = call i32 @getch()
  %r254 = add i32 %r253, 0
  br label %bb9

bb11:
  %r255 = icmp ne i32 %r237, 0
  br i1 %r255, label %bb13, label %bb14

bb13:
  %r256 = sub i32 0, %r246
  ret i32 %r256
bb14:
  ret i32 %r246
}

define void @addedge( i32 %r126, i32 %r128 ) {
bb16:
  %r257 = add i32 0, 0
  %r258 = add i32 %r126, 0
  %r259 = add i32 0, 0
  %r260 = add i32 %r128, 0
  %r261 = load i32, i32* @cnt
  %r132 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r261
  store i32 %r260, i32* %r132
  %r134 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r258
  %r262 = load i32, i32* %r134
  %r263 = load i32, i32* @cnt
  %r137 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r263
  store i32 %r262, i32* %r137
  %r264 = load i32, i32* @cnt
  %r140 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r258
  store i32 %r264, i32* %r140
  %r265 = load i32, i32* @cnt
  %r266 = add i32 %r265, 1
  store i32 %r266, i32* @cnt
  %r267 = load i32, i32* @cnt
  %r145 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r267
  store i32 %r258, i32* %r145
  %r147 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r260
  %r268 = load i32, i32* %r147
  %r269 = load i32, i32* @cnt
  %r150 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r269
  store i32 %r268, i32* %r150
  %r270 = load i32, i32* @cnt
  %r153 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r260
  store i32 %r270, i32* %r153
  %r271 = load i32, i32* @cnt
  %r272 = add i32 %r271, 1
  store i32 %r272, i32* @cnt
  ret void
}

define void @init( ) {
bb17:
  %r273 = add i32 0, 0
  %r274 = add i32 0, 0
  br label %bb18

bb18:
  %r275 = phi i32 [ %r274, %bb17 ], [ %r279, %bb19 ]
  %r276 = icmp slt i32 %r275, 1005
  br i1 %r276, label %bb19, label %bb20

bb19:
  %r277 = sub i32 0, 1
  %r161 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r275
  store i32 %r277, i32* %r161
  %r278 = add i32 %r275, 1
  %r279 = add i32 %r278, 0
  br label %bb18

bb20:
  ret void
}

define void @clear( ) {
bb21:
  %r280 = add i32 0, 0
  %r281 = add i32 1, 0
  br label %bb22

bb22:
  %r282 = phi i32 [ %r281, %bb21 ], [ %r286, %bb23 ]
  %r283 = load i32, i32* @n
  %r284 = icmp sle i32 %r282, %r283
  br i1 %r284, label %bb23, label %bb24

bb23:
  %r169 = getelementptr [1005 x i32 ], [1005 x i32 ]* @vis, i32 0, i32 %r282
  store i32 0, i32* %r169
  %r285 = add i32 %r282, 1
  %r286 = add i32 %r285, 0
  br label %bb22

bb24:
  ret void
}

define i32 @same( i32 %r172, i32 %r174 ) {
bb25:
  %r287 = add i32 0, 0
  %r288 = add i32 0, 0
  %r289 = add i32 0, 0
  %r290 = add i32 %r172, 0
  %r291 = add i32 0, 0
  %r292 = add i32 %r174, 0
  %r177 = getelementptr [1005 x i32 ], [1005 x i32 ]* @vis, i32 0, i32 %r290
  store i32 1, i32* %r177
  %r293 = icmp eq i32 %r290, %r292
  br i1 %r293, label %bb26, label %bb27

bb26:
  ret i32 1
bb27:
  br label %bb28

bb28:
  %r183 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r290
  %r294 = load i32, i32* %r183
  %r295 = add i32 %r294, 0
  br label %bb29

bb29:
  %r296 = phi i32 [ %r295, %bb28 ], [ %r306, %bb34 ]
  %r297 = sub i32 0, 1
  %r298 = icmp ne i32 %r296, %r297
  br i1 %r298, label %bb30, label %bb31

bb30:
  %r190 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r296
  %r299 = load i32, i32* %r190
  %r300 = add i32 %r299, 0
  %r193 = getelementptr [1005 x i32 ], [1005 x i32 ]* @vis, i32 0, i32 %r300
  %r301 = load i32, i32* %r193
  %r302 = icmp eq i32 %r301, 0
  br i1 %r302, label %bb35, label %bb33

bb35:
  %r303 = call i32 @same(i32 %r300, i32 %r292)
  %r304 = icmp ne i32 %r303, 0
  br i1 %r304, label %bb32, label %bb33

bb32:
  ret i32 1
bb33:
  br label %bb34

bb34:
  %r201 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r296
  %r305 = load i32, i32* %r201
  %r306 = add i32 %r305, 0
  br label %bb29

bb31:
  ret i32 0
}

define i32 @main( ) {
bb36:
  call void @_sysy_starttime(i32 74)
  %r307 = call i32 @quickread()
  store i32 %r307, i32* @n
  %r308 = call i32 @quickread()
  store i32 %r308, i32* @m
  call void @init()
  %r309 = add i32 0, 0
  %r310 = add i32 0, 0
  %r311 = add i32 0, 0
  %r312 = add i32 0, 0
  %r313 = add i32 0, 0
  %r314 = add i32 0, 0
  br label %bb37

bb37:
  %r315 = load i32, i32* @m
  %r316 = icmp ne i32 %r315, 0
  br i1 %r316, label %bb38, label %bb39

bb38:
  %r317 = call i32 @getch()
  %r318 = add i32 %r317, 0
  br label %bb40

bb40:
  %r319 = phi i32 [ %r318, %bb38 ], [ %r323, %bb41 ]
  %r320 = icmp ne i32 %r319, 81
  br i1 %r320, label %bb43, label %bb42

bb43:
  %r321 = icmp ne i32 %r319, 85
  br i1 %r321, label %bb41, label %bb42

bb41:
  %r322 = call i32 @getch()
  %r323 = add i32 %r322, 0
  br label %bb40

bb42:
  %r324 = icmp eq i32 %r319, 81
  br i1 %r324, label %bb44, label %bb45

bb44:
  %r325 = call i32 @quickread()
  %r326 = add i32 %r325, 0
  %r327 = call i32 @quickread()
  %r328 = add i32 %r327, 0
  call void @clear()
  %r329 = call i32 @same(i32 %r326, i32 %r328)
  call void @putint(i32 %r329)
  call void @putch(i32 10)
  br label %bb46

bb45:
  %r332 = call i32 @quickread()
  %r333 = add i32 %r332, 0
  %r334 = call i32 @quickread()
  %r335 = add i32 %r334, 0
  call void @addedge(i32 %r333, i32 %r335)
  br label %bb46

bb46:
  %r330 = load i32, i32* @m
  %r331 = sub i32 %r330, 1
  store i32 %r331, i32* @m
  br label %bb37

bb39:
  call void @_sysy_stoptime(i32 96)
  ret i32 0
}

