declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@N = global i32 0
@newline = global i32 0
define i32 @mod( i32 %r100, i32 %r102 ) {
bb1:
  %r143 = add i32 0, 0
  %r144 = add i32 %r100, 0
  %r145 = add i32 0, 0
  %r146 = add i32 %r102, 0
  %r147 = sdiv i32 %r144, %r146
  %r148 = mul i32 %r147, %r146
  %r149 = sub i32 %r144, %r148
  ret i32 %r149
}

define i32 @split( i32 %r111, i32* %r113 ) {
bb2:
  %r150 = add i32 0, 0
  %r151 = add i32 %r111, 0
  %r152 = add i32 0, 0
  %r153 = load i32, i32* @N
  %r154 = sub i32 %r153, 1
  %r155 = add i32 %r154, 0
  br label %bb3

bb3:
  %r156 = phi i32 [ %r155, %bb2 ], [ %r164, %bb4 ]
  %r157 = phi i32 [ %r151, %bb2 ], [ %r162, %bb4 ]
  %r158 = sub i32 0, 1
  %r159 = icmp ne i32 %r156, %r158
  br i1 %r159, label %bb4, label %bb5

bb4:
  %r160 = call i32 @mod(i32 %r157, i32 10)
  %r123 = getelementptr i32, i32* %r113, i32 %r156
  store i32 %r160, i32* %r123
  %r161 = sdiv i32 %r157, 10
  %r162 = add i32 %r161, 0
  %r163 = sub i32 %r156, 1
  %r164 = add i32 %r163, 0
  br label %bb3

bb5:
  ret i32 0
}

define i32 @main( ) {
bb6:
  call void @_sysy_starttime(i32 26)
  store i32 4, i32* @N
  store i32 10, i32* @newline
  %r165 = add i32 0, 0
  %r166 = add i32 0, 0
  %r130 = alloca [ 4 x i32 ]
  %r167 = add i32 1478, 0
  %r168 = call i32 @split(i32 %r167, i32* %r130)
  %r169 = add i32 %r168, 0
  %r170 = add i32 0, 0
  %r171 = add i32 0, 0
  br label %bb7

bb7:
  %r172 = phi i32 [ %r171, %bb6 ], [ %r178, %bb8 ]
  %r173 = icmp slt i32 %r172, 4
  br i1 %r173, label %bb8, label %bb9

bb8:
  %r137 = getelementptr [4 x i32 ], [4 x i32 ]* %r130, i32 0, i32 %r172
  %r174 = load i32, i32* %r137
  %r175 = add i32 %r174, 0
  call void @putint(i32 %r175)
  %r176 = load i32, i32* @newline
  call void @putch(i32 %r176)
  %r177 = add i32 %r172, 1
  %r178 = add i32 %r177, 0
  br label %bb7

bb9:
  call void @_sysy_stoptime(i32 42)
  ret i32 0
}

