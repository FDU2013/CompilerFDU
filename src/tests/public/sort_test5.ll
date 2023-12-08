declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@n = global i32 0
define i32 @swap( i32* %r100, i32 %r101, i32 %r103 ) {
bb1:
  %r219 = add i32 0, 0
  %r220 = add i32 %r101, 0
  %r221 = add i32 0, 0
  %r222 = add i32 %r103, 0
  %r223 = add i32 0, 0
  %r107 = getelementptr i32, i32* %r100, i32 %r220
  %r224 = load i32, i32* %r107
  %r225 = add i32 %r224, 0
  %r110 = getelementptr i32, i32* %r100, i32 %r222
  %r226 = load i32, i32* %r110
  %r113 = getelementptr i32, i32* %r100, i32 %r220
  store i32 %r226, i32* %r113
  %r116 = getelementptr i32, i32* %r100, i32 %r222
  store i32 %r225, i32* %r116
  ret i32 0
}

define i32 @heap_ajust( i32* %r117, i32 %r118, i32 %r120 ) {
bb2:
  %r227 = add i32 0, 0
  %r228 = add i32 0, 0
  %r229 = add i32 %r118, 0
  %r230 = add i32 0, 0
  %r231 = add i32 %r120, 0
  %r232 = add i32 0, 0
  %r233 = add i32 %r229, 0
  %r234 = add i32 0, 0
  %r235 = mul i32 %r233, 2
  %r236 = add i32 %r235, 1
  %r237 = add i32 %r236, 0
  br label %bb3

bb3:
  %r238 = phi i32 [ %r233, %bb2 ], [ %r256, %bb12 ]
  %r239 = phi i32 [ %r237, %bb2 ], [ %r259, %bb12 ]
  %r240 = add i32 %r231, 1
  %r241 = icmp slt i32 %r239, %r240
  br i1 %r241, label %bb4, label %bb5

bb4:
  %r242 = add i32 %r239, 1
  %r243 = add i32 %r242, 0
  %r244 = icmp slt i32 %r239, %r231
  br i1 %r244, label %bb9, label %bb7

bb9:
  %r139 = getelementptr i32, i32* %r117, i32 %r239
  %r245 = load i32, i32* %r139
  %r142 = getelementptr i32, i32* %r117, i32 %r243
  %r246 = load i32, i32* %r142
  %r247 = icmp slt i32 %r245, %r246
  br i1 %r247, label %bb6, label %bb7

bb6:
  %r248 = add i32 %r239, 1
  %r249 = add i32 %r248, 0
  br label %bb8

bb7:
  br label %bb8

bb8:
  %r250 = phi i32 [ %r249, %bb6 ], [ %r239, %bb7 ]
  %r148 = getelementptr i32, i32* %r117, i32 %r238
  %r251 = load i32, i32* %r148
  %r151 = getelementptr i32, i32* %r117, i32 %r250
  %r252 = load i32, i32* %r151
  %r253 = icmp sgt i32 %r251, %r252
  br i1 %r253, label %bb10, label %bb11

bb10:
  ret i32 0
bb11:
  %r254 = call i32 @swap(i32* %r117, i32 %r238, i32 %r250)
  %r255 = add i32 %r254, 0
  %r256 = add i32 %r250, 0
  %r257 = mul i32 %r256, 2
  %r258 = add i32 %r257, 1
  %r259 = add i32 %r258, 0
  br label %bb12

bb12:
  br label %bb3

bb5:
  ret i32 0
}

define i32 @heap_sort( i32* %r161, i32 %r162 ) {
bb13:
  %r260 = add i32 0, 0
  %r261 = add i32 0, 0
  %r262 = add i32 %r162, 0
  %r263 = add i32 0, 0
  %r264 = add i32 0, 0
  %r265 = sdiv i32 %r262, 2
  %r266 = sub i32 %r265, 1
  %r267 = add i32 %r266, 0
  br label %bb14

bb14:
  %r268 = phi i32 [ %r267, %bb13 ], [ %r276, %bb15 ]
  %r269 = sub i32 0, 1
  %r270 = icmp sgt i32 %r268, %r269
  br i1 %r270, label %bb15, label %bb16

bb15:
  %r271 = sub i32 %r262, 1
  %r272 = add i32 %r271, 0
  %r273 = call i32 @heap_ajust(i32* %r161, i32 %r268, i32 %r272)
  %r274 = add i32 %r273, 0
  %r275 = sub i32 %r268, 1
  %r276 = add i32 %r275, 0
  br label %bb14

bb16:
  %r277 = sub i32 %r262, 1
  %r278 = add i32 %r277, 0
  br label %bb17

bb17:
  %r279 = phi i32 [ %r278, %bb16 ], [ %r289, %bb18 ]
  %r280 = icmp sgt i32 %r279, 0
  br i1 %r280, label %bb18, label %bb19

bb18:
  %r281 = add i32 0, 0
  %r282 = call i32 @swap(i32* %r161, i32 %r281, i32 %r279)
  %r283 = add i32 %r282, 0
  %r284 = sub i32 %r279, 1
  %r285 = add i32 %r284, 0
  %r286 = call i32 @heap_ajust(i32* %r161, i32 %r281, i32 %r285)
  %r287 = add i32 %r286, 0
  %r288 = sub i32 %r279, 1
  %r289 = add i32 %r288, 0
  br label %bb17

bb19:
  ret i32 0
}

define i32 @main( ) {
bb20:
  %r290 = add i32 0, 0
  call void @_sysy_starttime(i32 50)
  store i32 10, i32* @n
  %r194 = alloca [ 10 x i32 ]
  %r195 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 0
  store i32 4, i32* %r195
  %r196 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 1
  store i32 3, i32* %r196
  %r197 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 2
  store i32 9, i32* %r197
  %r198 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 3
  store i32 2, i32* %r198
  %r199 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 4
  store i32 0, i32* %r199
  %r200 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 5
  store i32 1, i32* %r200
  %r201 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 6
  store i32 6, i32* %r201
  %r202 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 7
  store i32 5, i32* %r202
  %r203 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 8
  store i32 7, i32* %r203
  %r204 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 9
  store i32 8, i32* %r204
  %r291 = add i32 0, 0
  %r292 = add i32 0, 0
  %r293 = load i32, i32* @n
  %r294 = call i32 @heap_sort(i32* %r194, i32 %r293)
  %r295 = add i32 %r294, 0
  br label %bb21

bb21:
  %r296 = phi i32 [ %r295, %bb20 ], [ %r303, %bb22 ]
  %r297 = load i32, i32* @n
  %r298 = icmp slt i32 %r296, %r297
  br i1 %r298, label %bb22, label %bb23

bb22:
  %r213 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 %r296
  %r299 = load i32, i32* %r213
  %r300 = add i32 %r299, 0
  call void @putint(i32 %r300)
  %r301 = add i32 10, 0
  call void @putch(i32 %r301)
  %r302 = add i32 %r296, 1
  %r303 = add i32 %r302, 0
  br label %bb21

bb23:
  call void @_sysy_stoptime(i32 66)
  ret i32 0
}

