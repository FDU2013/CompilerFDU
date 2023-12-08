declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @uniquePaths( i32 %r100, i32 %r102 ) {
bb1:
  %r183 = add i32 0, 0
  %r184 = add i32 0, 0
  %r185 = add i32 0, 0
  %r186 = add i32 0, 0
  %r187 = add i32 0, 0
  %r108 = alloca [ 9 x i32 ]
  %r188 = add i32 0, 0
  %r189 = add i32 %r100, 0
  %r190 = add i32 0, 0
  %r191 = add i32 %r102, 0
  %r192 = icmp eq i32 %r189, 1
  br i1 %r192, label %bb2, label %bb5

bb5:
  %r193 = icmp eq i32 %r191, 1
  br i1 %r193, label %bb2, label %bb3

bb2:
  ret i32 1
bb3:
  br label %bb4

bb4:
  %r194 = add i32 0, 0
  br label %bb6

bb6:
  %r195 = phi i32 [ %r194, %bb4 ], [ %r202, %bb7 ]
  %r196 = icmp slt i32 %r195, %r189
  br i1 %r196, label %bb7, label %bb8

bb7:
  %r197 = mul i32 %r195, 3
  %r198 = add i32 %r197, %r191
  %r199 = sub i32 %r198, 1
  %r200 = add i32 %r199, 0
  %r123 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r200
  store i32 1, i32* %r123
  %r201 = add i32 %r195, 1
  %r202 = add i32 %r201, 0
  br label %bb6

bb8:
  %r203 = add i32 0, 0
  br label %bb9

bb9:
  %r204 = phi i32 [ %r203, %bb8 ], [ %r211, %bb10 ]
  %r205 = icmp slt i32 %r204, %r191
  br i1 %r205, label %bb10, label %bb11

bb10:
  %r206 = sub i32 %r189, 1
  %r207 = mul i32 %r206, 3
  %r208 = add i32 %r207, %r204
  %r209 = add i32 %r208, 0
  %r135 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r209
  store i32 1, i32* %r135
  %r210 = add i32 %r204, 1
  %r211 = add i32 %r210, 0
  br label %bb9

bb11:
  %r212 = sub i32 %r189, 2
  %r213 = add i32 %r212, 0
  br label %bb12

bb12:
  %r214 = phi i32 [ %r213, %bb11 ], [ %r239, %bb17 ]
  %r215 = sub i32 0, 1
  %r216 = icmp sgt i32 %r214, %r215
  br i1 %r216, label %bb13, label %bb14

bb13:
  %r217 = sub i32 %r191, 2
  %r218 = add i32 %r217, 0
  br label %bb15

bb15:
  %r219 = phi i32 [ %r218, %bb13 ], [ %r237, %bb16 ]
  %r220 = sub i32 0, 1
  %r221 = icmp sgt i32 %r219, %r220
  br i1 %r221, label %bb16, label %bb17

bb16:
  %r222 = mul i32 %r214, 3
  %r223 = add i32 %r222, %r219
  %r224 = add i32 %r223, 0
  %r225 = add i32 %r214, 1
  %r226 = mul i32 %r225, 3
  %r227 = add i32 %r226, %r219
  %r228 = add i32 %r227, 0
  %r229 = mul i32 %r214, 3
  %r230 = add i32 %r229, %r219
  %r231 = add i32 %r230, 1
  %r232 = add i32 %r231, 0
  %r163 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r228
  %r233 = load i32, i32* %r163
  %r166 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r232
  %r234 = load i32, i32* %r166
  %r235 = add i32 %r233, %r234
  %r170 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r224
  store i32 %r235, i32* %r170
  %r236 = sub i32 %r219, 1
  %r237 = add i32 %r236, 0
  br label %bb15

bb17:
  %r238 = sub i32 %r214, 1
  %r239 = add i32 %r238, 0
  br label %bb12

bb14:
  %r175 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 0
  %r240 = load i32, i32* %r175
  ret i32 %r240
}

define i32 @main( ) {
bb18:
  call void @_sysy_starttime(i32 40)
  %r241 = add i32 0, 0
  %r242 = add i32 0, 0
  %r243 = add i32 3, 0
  %r244 = call i32 @uniquePaths(i32 %r243, i32 %r243)
  %r245 = add i32 %r244, 0
  call void @_sysy_stoptime(i32 45)
  ret i32 %r245
}

