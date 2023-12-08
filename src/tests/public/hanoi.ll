declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define void @move( i32 %r100, i32 %r102 ) {
bb1:
  %r137 = add i32 0, 0
  %r138 = add i32 %r100, 0
  %r139 = add i32 0, 0
  %r140 = add i32 %r102, 0
  call void @putint(i32 %r138)
  call void @putch(i32 32)
  call void @putint(i32 %r140)
  call void @putch(i32 44)
  call void @putch(i32 32)
  ret void
}

define void @hanoi( i32 %r106, i32 %r108, i32 %r110, i32 %r112 ) {
bb2:
  %r141 = add i32 0, 0
  %r142 = add i32 %r106, 0
  %r143 = add i32 0, 0
  %r144 = add i32 %r108, 0
  %r145 = add i32 0, 0
  %r146 = add i32 %r110, 0
  %r147 = add i32 0, 0
  %r148 = add i32 %r112, 0
  %r149 = icmp eq i32 %r142, 1
  br i1 %r149, label %bb3, label %bb4

bb3:
  call void @move(i32 %r144, i32 %r148)
  br label %bb5

bb4:
  %r150 = sub i32 %r142, 1
  call void @hanoi(i32 %r150, i32 %r144, i32 %r148, i32 %r146)
  call void @move(i32 %r144, i32 %r148)
  %r151 = sub i32 %r142, 1
  call void @hanoi(i32 %r151, i32 %r146, i32 %r144, i32 %r148)
  br label %bb5

bb5:
  ret void
}

define i32 @main( ) {
bb6:
  call void @_sysy_starttime(i32 21)
  %r152 = add i32 0, 0
  %r153 = call i32 @getint()
  %r154 = add i32 %r153, 0
  br label %bb7

bb7:
  %r155 = phi i32 [ %r154, %bb6 ], [ %r159, %bb8 ]
  %r156 = icmp sgt i32 %r155, 0
  br i1 %r156, label %bb8, label %bb9

bb8:
  %r157 = call i32 @getint()
  call void @hanoi(i32 %r157, i32 1, i32 2, i32 3)
  call void @putch(i32 10)
  %r158 = sub i32 %r155, 1
  %r159 = add i32 %r158, 0
  br label %bb7

bb9:
  call void @_sysy_stoptime(i32 28)
  ret i32 0
}

