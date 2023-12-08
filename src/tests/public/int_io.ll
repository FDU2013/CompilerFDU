declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@ascii_0 = global i32 48
define i32 @my_getint( ) {
bb1:
  %r167 = add i32 0, 0
  %r168 = add i32 0, 0
  %r169 = add i32 0, 0
  br label %bb2

bb2:
  %r170 = phi i32 [ %r169, %bb1 ], [ %r175, %bb5 ]
  %r171 = icmp sgt i32 1, 0
  br i1 %r171, label %bb3, label %bb4

bb3:
  %r172 = call i32 @getch()
  %r173 = load i32, i32* @ascii_0
  %r174 = sub i32 %r172, %r173
  %r175 = add i32 %r174, 0
  %r176 = icmp slt i32 %r175, 0
  br i1 %r176, label %bb5, label %bb8

bb8:
  %r177 = icmp sgt i32 %r175, 9
  br i1 %r177, label %bb5, label %bb6

bb5:
  br label %bb2

bb6:
  br label %bb4

bb4:
  %r178 = phi i32 [ %r170, %bb2 ], [ %r175, %bb6 ]
  %r179 = add i32 %r178, 0
  br label %bb9

bb9:
  %r180 = phi i32 [ %r179, %bb4 ], [ %r190, %bb14 ]
  %r181 = icmp sgt i32 1, 0
  br i1 %r181, label %bb10, label %bb11

bb10:
  %r182 = call i32 @getch()
  %r183 = load i32, i32* @ascii_0
  %r184 = sub i32 %r182, %r183
  %r185 = add i32 %r184, 0
  %r186 = icmp sge i32 %r185, 0
  br i1 %r186, label %bb15, label %bb13

bb15:
  %r187 = icmp sle i32 %r185, 9
  br i1 %r187, label %bb12, label %bb13

bb12:
  %r188 = mul i32 %r180, 10
  %r189 = add i32 %r188, %r185
  %r190 = add i32 %r189, 0
  br label %bb14

bb13:
  br label %bb11

bb14:
  br label %bb9

bb11:
  ret i32 %r180
}

define i32 @mod( i32 %r124, i32 %r126 ) {
bb16:
  %r191 = add i32 0, 0
  %r192 = add i32 %r124, 0
  %r193 = add i32 0, 0
  %r194 = add i32 %r126, 0
  %r195 = sdiv i32 %r192, %r194
  %r196 = mul i32 %r195, %r194
  %r197 = sub i32 %r192, %r196
  ret i32 %r197
}

define void @my_putint( i32 %r135 ) {
bb17:
  %r198 = add i32 0, 0
  %r199 = add i32 %r135, 0
  %r137 = alloca [ 16 x i32 ]
  %r200 = add i32 0, 0
  %r201 = add i32 0, 0
  br label %bb18

bb18:
  %r202 = phi i32 [ %r201, %bb17 ], [ %r211, %bb19 ]
  %r203 = phi i32 [ %r199, %bb17 ], [ %r209, %bb19 ]
  %r204 = icmp sgt i32 %r203, 0
  br i1 %r204, label %bb19, label %bb20

bb19:
  %r205 = call i32 @mod(i32 %r203, i32 10)
  %r206 = load i32, i32* @ascii_0
  %r207 = add i32 %r205, %r206
  %r146 = getelementptr [16 x i32 ], [16 x i32 ]* %r137, i32 0, i32 %r202
  store i32 %r207, i32* %r146
  %r208 = sdiv i32 %r203, 10
  %r209 = add i32 %r208, 0
  %r210 = add i32 %r202, 1
  %r211 = add i32 %r210, 0
  br label %bb18

bb20:
  br label %bb21

bb21:
  %r212 = phi i32 [ %r202, %bb20 ], [ %r215, %bb22 ]
  %r213 = icmp sgt i32 %r212, 0
  br i1 %r213, label %bb22, label %bb23

bb22:
  %r214 = sub i32 %r212, 1
  %r215 = add i32 %r214, 0
  %r156 = getelementptr [16 x i32 ], [16 x i32 ]* %r137, i32 0, i32 %r215
  %r216 = load i32, i32* %r156
  call void @putch(i32 %r216)
  br label %bb21

bb23:
  ret void
}

define i32 @main( ) {
bb24:
  %r217 = add i32 0, 0
  call void @_sysy_starttime(i32 51)
  %r218 = add i32 0, 0
  %r219 = call i32 @my_getint()
  %r220 = add i32 %r219, 0
  br label %bb25

bb25:
  %r221 = phi i32 [ %r220, %bb24 ], [ %r226, %bb26 ]
  %r222 = icmp sgt i32 %r221, 0
  br i1 %r222, label %bb26, label %bb27

bb26:
  %r223 = call i32 @my_getint()
  %r224 = add i32 %r223, 0
  call void @my_putint(i32 %r224)
  call void @putch(i32 10)
  %r225 = sub i32 %r221, 1
  %r226 = add i32 %r225, 0
  br label %bb25

bb27:
  call void @_sysy_stoptime(i32 58)
  ret i32 0
}

