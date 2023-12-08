declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@N = global i32 0
define i32 @insert( i32* %r100, i32 %r101 ) {
bb1:
  %r158 = add i32 0, 0
  %r159 = add i32 0, 0
  %r160 = add i32 %r101, 0
  %r161 = add i32 0, 0
  %r162 = add i32 0, 0
  %r163 = add i32 0, 0
  br label %bb2

bb2:
  %r164 = phi i32 [ %r163, %bb1 ], [ %r170, %bb3 ]
  %r107 = getelementptr i32, i32* %r100, i32 %r164
  %r165 = load i32, i32* %r107
  %r166 = icmp sgt i32 %r160, %r165
  br i1 %r166, label %bb5, label %bb4

bb5:
  %r167 = load i32, i32* @N
  %r168 = icmp slt i32 %r164, %r167
  br i1 %r168, label %bb3, label %bb4

bb3:
  %r169 = add i32 %r164, 1
  %r170 = add i32 %r169, 0
  br label %bb2

bb4:
  %r171 = load i32, i32* @N
  %r172 = add i32 %r171, 0
  br label %bb6

bb6:
  %r173 = phi i32 [ %r172, %bb4 ], [ %r179, %bb7 ]
  %r174 = icmp sgt i32 %r173, %r164
  br i1 %r174, label %bb7, label %bb8

bb7:
  %r175 = sub i32 %r173, 1
  %r176 = add i32 %r175, 0
  %r123 = getelementptr i32, i32* %r100, i32 %r176
  %r177 = load i32, i32* %r123
  %r126 = getelementptr i32, i32* %r100, i32 %r173
  store i32 %r177, i32* %r126
  %r129 = getelementptr i32, i32* %r100, i32 %r164
  store i32 %r160, i32* %r129
  %r178 = sub i32 %r173, 1
  %r179 = add i32 %r178, 0
  br label %bb6

bb8:
  ret i32 0
}

define i32 @main( ) {
bb9:
  call void @_sysy_starttime(i32 27)
  store i32 10, i32* @N
  %r132 = alloca [ 11 x i32 ]
  %r133 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 0
  store i32 1, i32* %r133
  %r134 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 1
  store i32 3, i32* %r134
  %r135 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 2
  store i32 4, i32* %r135
  %r136 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 3
  store i32 7, i32* %r136
  %r137 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 4
  store i32 8, i32* %r137
  %r138 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 5
  store i32 11, i32* %r138
  %r139 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 6
  store i32 13, i32* %r139
  %r140 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 7
  store i32 18, i32* %r140
  %r141 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 8
  store i32 56, i32* %r141
  %r142 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 9
  store i32 78, i32* %r142
  %r180 = add i32 0, 0
  %r181 = add i32 0, 0
  %r182 = add i32 0, 0
  %r183 = call i32 @getint()
  %r184 = add i32 %r183, 0
  %r185 = call i32 @insert(i32* %r132, i32 %r184)
  %r186 = add i32 %r185, 0
  br label %bb10

bb10:
  %r187 = phi i32 [ %r182, %bb9 ], [ %r194, %bb11 ]
  %r188 = load i32, i32* @N
  %r189 = icmp slt i32 %r187, %r188
  br i1 %r189, label %bb11, label %bb12

bb11:
  %r152 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 %r187
  %r190 = load i32, i32* %r152
  %r191 = add i32 %r190, 0
  call void @putint(i32 %r191)
  %r192 = add i32 10, 0
  call void @putch(i32 %r192)
  %r193 = add i32 %r187, 1
  %r194 = add i32 %r193, 0
  br label %bb10

bb12:
  call void @_sysy_stoptime(i32 54)
  ret i32 0
}

