declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @canJump( i32* %r100, i32 %r101 ) {
bb1:
  %r179 = add i32 0, 0
  %r180 = add i32 0, 0
  %r181 = add i32 0, 0
  %r110 = alloca [ 10 x i32 ]
  %r182 = add i32 0, 0
  %r183 = add i32 %r101, 0
  %r184 = icmp eq i32 %r183, 1
  br i1 %r184, label %bb2, label %bb3

bb2:
  ret i32 1
bb3:
  br label %bb4

bb4:
  %r105 = getelementptr i32, i32* %r100, i32 0
  %r185 = load i32, i32* %r105
  %r186 = sub i32 %r183, 2
  %r187 = icmp sgt i32 %r185, %r186
  br i1 %r187, label %bb5, label %bb6

bb5:
  ret i32 1
bb6:
  br label %bb7

bb7:
  %r188 = add i32 0, 0
  br label %bb8

bb8:
  %r189 = phi i32 [ %r188, %bb7 ], [ %r193, %bb9 ]
  %r190 = sub i32 %r183, 1
  %r191 = icmp slt i32 %r189, %r190
  br i1 %r191, label %bb9, label %bb10

bb9:
  %r117 = getelementptr [10 x i32 ], [10 x i32 ]* %r110, i32 0, i32 %r189
  store i32 0, i32* %r117
  %r192 = add i32 %r189, 1
  %r193 = add i32 %r192, 0
  br label %bb8

bb10:
  %r194 = sub i32 %r183, 1
  %r195 = add i32 %r194, 0
  %r124 = getelementptr [10 x i32 ], [10 x i32 ]* %r110, i32 0, i32 %r195
  store i32 1, i32* %r124
  %r196 = sub i32 %r183, 2
  %r197 = add i32 %r196, 0
  br label %bb11

bb11:
  %r198 = phi i32 [ %r197, %bb10 ], [ %r218, %bb19 ]
  %r199 = sub i32 0, 1
  %r200 = icmp sgt i32 %r198, %r199
  br i1 %r200, label %bb12, label %bb13

bb12:
  %r132 = getelementptr i32, i32* %r100, i32 %r198
  %r201 = load i32, i32* %r132
  %r202 = sub i32 %r183, 1
  %r203 = sub i32 %r202, %r198
  %r204 = icmp slt i32 %r201, %r203
  br i1 %r204, label %bb14, label %bb15

bb14:
  %r140 = getelementptr i32, i32* %r100, i32 %r198
  %r205 = load i32, i32* %r140
  %r206 = add i32 %r205, 0
  br label %bb16

bb15:
  %r219 = sub i32 %r183, 1
  %r220 = sub i32 %r219, %r198
  %r221 = add i32 %r220, 0
  br label %bb16

bb16:
  %r207 = phi i32 [ %r206, %bb14 ], [ %r221, %bb15 ]
  br label %bb17

bb17:
  %r208 = phi i32 [ %r207, %bb16 ], [ %r216, %bb22 ]
  %r209 = sub i32 0, 1
  %r210 = icmp sgt i32 %r208, %r209
  br i1 %r210, label %bb18, label %bb19

bb18:
  %r211 = add i32 %r198, %r208
  %r212 = add i32 %r211, 0
  %r153 = getelementptr [10 x i32 ], [10 x i32 ]* %r110, i32 0, i32 %r212
  %r213 = load i32, i32* %r153
  %r214 = icmp ne i32 %r213, 0
  br i1 %r214, label %bb20, label %bb21

bb20:
  %r157 = getelementptr [10 x i32 ], [10 x i32 ]* %r110, i32 0, i32 %r198
  store i32 1, i32* %r157
  br label %bb22

bb21:
  br label %bb22

bb22:
  %r215 = sub i32 %r208, 1
  %r216 = add i32 %r215, 0
  br label %bb17

bb19:
  %r217 = sub i32 %r198, 1
  %r218 = add i32 %r217, 0
  br label %bb11

bb13:
  %r162 = getelementptr [10 x i32 ], [10 x i32 ]* %r110, i32 0, i32 0
  %r222 = load i32, i32* %r162
  ret i32 %r222
}

define i32 @main( ) {
bb23:
  call void @_sysy_starttime(i32 42)
  %r223 = add i32 0, 0
  %r165 = alloca [ 10 x i32 ]
  %r166 = getelementptr [10 x i32 ], [10 x i32 ]* %r165, i32 0, i32 0
  store i32 3, i32* %r166
  %r167 = getelementptr [10 x i32 ], [10 x i32 ]* %r165, i32 0, i32 1
  store i32 3, i32* %r167
  %r168 = getelementptr [10 x i32 ], [10 x i32 ]* %r165, i32 0, i32 2
  store i32 9, i32* %r168
  %r169 = getelementptr [10 x i32 ], [10 x i32 ]* %r165, i32 0, i32 3
  store i32 0, i32* %r169
  %r170 = getelementptr [10 x i32 ], [10 x i32 ]* %r165, i32 0, i32 4
  store i32 0, i32* %r170
  %r171 = getelementptr [10 x i32 ], [10 x i32 ]* %r165, i32 0, i32 5
  store i32 1, i32* %r171
  %r172 = getelementptr [10 x i32 ], [10 x i32 ]* %r165, i32 0, i32 6
  store i32 1, i32* %r172
  %r173 = getelementptr [10 x i32 ], [10 x i32 ]* %r165, i32 0, i32 7
  store i32 5, i32* %r173
  %r174 = getelementptr [10 x i32 ], [10 x i32 ]* %r165, i32 0, i32 8
  store i32 7, i32* %r174
  %r175 = getelementptr [10 x i32 ], [10 x i32 ]* %r165, i32 0, i32 9
  store i32 8, i32* %r175
  %r224 = add i32 10, 0
  %r225 = call i32 @canJump(i32* %r165, i32 %r224)
  %r226 = add i32 %r225, 0
  call void @_sysy_stoptime(i32 49)
  ret i32 %r226
}

