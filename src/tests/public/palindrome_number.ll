declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @mod( i32 %r100, i32 %r102 ) {
bb1:
  %r146 = add i32 0, 0
  %r147 = add i32 %r100, 0
  %r148 = add i32 0, 0
  %r149 = add i32 %r102, 0
  %r150 = sdiv i32 %r147, %r149
  %r151 = mul i32 %r150, %r149
  %r152 = sub i32 %r147, %r151
  ret i32 %r152
}

define i32 @palindrome( i32 %r111 ) {
bb2:
  %r153 = add i32 0, 0
  %r154 = add i32 %r111, 0
  %r113 = alloca [ 4 x i32 ]
  %r155 = add i32 0, 0
  %r156 = add i32 0, 0
  %r157 = add i32 0, 0
  br label %bb3

bb3:
  %r158 = phi i32 [ %r157, %bb2 ], [ %r165, %bb4 ]
  %r159 = phi i32 [ %r154, %bb2 ], [ %r163, %bb4 ]
  %r160 = icmp slt i32 %r158, 4
  br i1 %r160, label %bb4, label %bb5

bb4:
  %r161 = call i32 @mod(i32 %r159, i32 10)
  %r121 = getelementptr [4 x i32 ], [4 x i32 ]* %r113, i32 0, i32 %r158
  store i32 %r161, i32* %r121
  %r162 = sdiv i32 %r159, 10
  %r163 = add i32 %r162, 0
  %r164 = add i32 %r158, 1
  %r165 = add i32 %r164, 0
  br label %bb3

bb5:
  %r126 = getelementptr [4 x i32 ], [4 x i32 ]* %r113, i32 0, i32 0
  %r166 = load i32, i32* %r126
  %r128 = getelementptr [4 x i32 ], [4 x i32 ]* %r113, i32 0, i32 3
  %r167 = load i32, i32* %r128
  %r168 = icmp eq i32 %r166, %r167
  br i1 %r168, label %bb9, label %bb7

bb9:
  %r131 = getelementptr [4 x i32 ], [4 x i32 ]* %r113, i32 0, i32 1
  %r169 = load i32, i32* %r131
  %r133 = getelementptr [4 x i32 ], [4 x i32 ]* %r113, i32 0, i32 2
  %r170 = load i32, i32* %r133
  %r171 = icmp eq i32 %r169, %r170
  br i1 %r171, label %bb6, label %bb7

bb6:
  %r172 = add i32 1, 0
  br label %bb8

bb7:
  %r174 = add i32 0, 0
  br label %bb8

bb8:
  %r173 = phi i32 [ %r172, %bb6 ], [ %r174, %bb7 ]
  ret i32 %r173
}

define i32 @main( ) {
bb10:
  call void @_sysy_starttime(i32 30)
  %r175 = add i32 0, 0
  %r176 = add i32 1221, 0
  %r177 = add i32 0, 0
  %r178 = call i32 @palindrome(i32 %r176)
  %r179 = add i32 %r178, 0
  %r180 = icmp eq i32 %r179, 1
  br i1 %r180, label %bb11, label %bb12

bb11:
  call void @putint(i32 %r176)
  br label %bb13

bb12:
  %r182 = add i32 0, 0
  call void @putint(i32 %r182)
  br label %bb13

bb13:
  %r181 = add i32 10, 0
  call void @putch(i32 %r181)
  call void @_sysy_stoptime(i32 47)
  ret i32 0
}

