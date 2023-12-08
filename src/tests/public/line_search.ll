declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @main( ) {
bb1:
  %r142 = add i32 0, 0
  %r143 = add i32 0, 0
  %r144 = add i32 0, 0
  %r145 = add i32 0, 0
  %r146 = add i32 0, 0
  %r147 = add i32 0, 0
  %r148 = add i32 0, 0
  call void @_sysy_starttime(i32 3)
  %r149 = add i32 0, 0
  %r150 = add i32 0, 0
  %r102 = alloca [ 10 x i32 ]
  %r151 = add i32 0, 0
  %r152 = add i32 0, 0
  br label %bb2

bb2:
  %r153 = phi i32 [ %r152, %bb1 ], [ %r157, %bb3 ]
  %r154 = icmp slt i32 %r153, 10
  br i1 %r154, label %bb3, label %bb4

bb3:
  %r155 = add i32 %r153, 1
  %r108 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r153
  store i32 %r155, i32* %r108
  %r156 = add i32 %r153, 1
  %r157 = add i32 %r156, 0
  br label %bb2

bb4:
  %r158 = add i32 10, 0
  %r159 = call i32 @getint()
  %r160 = add i32 %r159, 0
  %r161 = sub i32 %r158, 1
  %r162 = add i32 %r161, 0
  %r163 = add i32 0, 0
  %r164 = add i32 %r162, %r163
  %r165 = sdiv i32 %r164, 2
  %r166 = add i32 %r165, 0
  %r167 = add i32 0, 0
  %r168 = add i32 0, 0
  %r169 = add i32 0, 0
  br label %bb5

bb5:
  %r170 = phi i32 [ %r169, %bb4 ], [ %r179, %bb11 ]
  %r171 = phi i32 [ %r167, %bb4 ], [ %r180, %bb11 ]
  %r172 = phi i32 [ %r168, %bb4 ], [ %r182, %bb11 ]
  %r173 = icmp slt i32 %r172, 10
  br i1 %r173, label %bb8, label %bb7

bb8:
  %r174 = icmp eq i32 %r171, 0
  br i1 %r174, label %bb6, label %bb7

bb6:
  %r130 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r172
  %r175 = load i32, i32* %r130
  %r176 = icmp eq i32 %r175, %r160
  br i1 %r176, label %bb9, label %bb10

bb9:
  %r177 = add i32 1, 0
  %r178 = add i32 %r172, 0
  br label %bb11

bb10:
  br label %bb11

bb11:
  %r179 = phi i32 [ %r178, %bb9 ], [ %r170, %bb10 ]
  %r180 = phi i32 [ %r177, %bb9 ], [ %r171, %bb10 ]
  %r181 = add i32 %r172, 1
  %r182 = add i32 %r181, 0
  br label %bb5

bb7:
  %r183 = icmp eq i32 %r171, 1
  br i1 %r183, label %bb12, label %bb13

bb12:
  call void @putint(i32 %r170)
  br label %bb14

bb13:
  %r185 = add i32 0, 0
  call void @putint(i32 %r185)
  br label %bb14

bb14:
  %r184 = add i32 10, 0
  call void @putch(i32 %r184)
  call void @_sysy_stoptime(i32 53)
  ret i32 0
}

