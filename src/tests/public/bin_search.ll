declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @main( ) {
bb1:
  %r152 = add i32 0, 0
  %r153 = add i32 0, 0
  %r154 = add i32 0, 0
  %r155 = add i32 0, 0
  %r156 = add i32 0, 0
  call void @_sysy_starttime(i32 3)
  %r157 = add i32 0, 0
  %r158 = add i32 0, 0
  %r102 = alloca [ 10 x i32 ]
  %r159 = add i32 0, 0
  %r160 = add i32 0, 0
  br label %bb2

bb2:
  %r161 = phi i32 [ %r160, %bb1 ], [ %r165, %bb3 ]
  %r162 = icmp slt i32 %r161, 10
  br i1 %r162, label %bb3, label %bb4

bb3:
  %r163 = add i32 %r161, 1
  %r108 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r161
  store i32 %r163, i32* %r108
  %r164 = add i32 %r161, 1
  %r165 = add i32 %r164, 0
  br label %bb2

bb4:
  %r166 = add i32 10, 0
  %r167 = call i32 @getint()
  %r168 = add i32 %r167, 0
  %r169 = sub i32 %r166, 1
  %r170 = add i32 %r169, 0
  %r171 = add i32 0, 0
  %r172 = add i32 %r170, %r171
  %r173 = sdiv i32 %r172, 2
  %r174 = add i32 %r173, 0
  br label %bb5

bb5:
  %r175 = phi i32 [ %r174, %bb4 ], [ %r183, %bb11 ]
  %r176 = phi i32 [ %r171, %bb4 ], [ %r188, %bb11 ]
  %r177 = phi i32 [ %r170, %bb4 ], [ %r189, %bb11 ]
  %r124 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r175
  %r178 = load i32, i32* %r124
  %r179 = icmp ne i32 %r178, %r168
  br i1 %r179, label %bb8, label %bb7

bb8:
  %r180 = icmp slt i32 %r176, %r177
  br i1 %r180, label %bb6, label %bb7

bb6:
  %r181 = add i32 %r177, %r176
  %r182 = sdiv i32 %r181, 2
  %r183 = add i32 %r182, 0
  %r137 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r183
  %r184 = load i32, i32* %r137
  %r185 = icmp slt i32 %r168, %r184
  br i1 %r185, label %bb9, label %bb10

bb9:
  %r186 = sub i32 %r183, 1
  %r187 = add i32 %r186, 0
  br label %bb11

bb10:
  %r190 = add i32 %r183, 1
  %r191 = add i32 %r190, 0
  br label %bb11

bb11:
  %r188 = phi i32 [ %r176, %bb9 ], [ %r191, %bb10 ]
  %r189 = phi i32 [ %r187, %bb9 ], [ %r177, %bb10 ]
  br label %bb5

bb7:
  %r146 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r175
  %r192 = load i32, i32* %r146
  %r193 = icmp eq i32 %r168, %r192
  br i1 %r193, label %bb12, label %bb13

bb12:
  call void @putint(i32 %r168)
  br label %bb14

bb13:
  %r195 = add i32 0, 0
  call void @putint(i32 %r195)
  br label %bb14

bb14:
  %r194 = add i32 10, 0
  call void @putch(i32 %r194)
  call void @_sysy_stoptime(i32 49)
  ret i32 0
}

