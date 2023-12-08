declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@TAPE_LEN = global i32 65536
@BUFFER_LEN = global i32 32768
@tape = global [ 65536 x i32 ] zeroinitializer
@program = global [ 32768 x i32 ] zeroinitializer
@ptr = global i32 0
define void @read_program( ) {
bb1:
  %r181 = add i32 0, 0
  %r182 = add i32 0, 0
  %r183 = add i32 0, 0
  %r184 = call i32 @getint()
  %r185 = add i32 %r184, 0
  br label %bb2

bb2:
  %r186 = phi i32 [ %r182, %bb1 ], [ %r190, %bb3 ]
  %r187 = icmp slt i32 %r186, %r185
  br i1 %r187, label %bb3, label %bb4

bb3:
  %r188 = call i32 @getch()
  %r108 = getelementptr [32768 x i32 ], [32768 x i32 ]* @program, i32 0, i32 %r186
  store i32 %r188, i32* %r108
  %r189 = add i32 %r186, 1
  %r190 = add i32 %r189, 0
  br label %bb2

bb4:
  %r112 = getelementptr [32768 x i32 ], [32768 x i32 ]* @program, i32 0, i32 %r186
  store i32 0, i32* %r112
  ret void
}

define void @interpret( i32* %r113 ) {
bb5:
  %r191 = add i32 0, 0
  %r192 = add i32 0, 0
  %r193 = add i32 0, 0
  %r194 = add i32 0, 0
  br label %bb6

bb6:
  %r195 = phi i32 [ %r194, %bb5 ], [ %r244, %bb29 ]
  %r118 = getelementptr i32, i32* %r113, i32 %r195
  %r196 = load i32, i32* %r118
  %r197 = icmp ne i32 %r196, 0
  br i1 %r197, label %bb7, label %bb8

bb7:
  %r122 = getelementptr i32, i32* %r113, i32 %r195
  %r198 = load i32, i32* %r122
  %r199 = add i32 %r198, 0
  %r200 = icmp eq i32 %r199, 62
  br i1 %r200, label %bb9, label %bb10

bb9:
  %r201 = load i32, i32* @ptr
  %r202 = add i32 %r201, 1
  store i32 %r202, i32* @ptr
  br label %bb11

bb10:
  br label %bb11

bb11:
  %r203 = icmp eq i32 %r199, 60
  br i1 %r203, label %bb12, label %bb13

bb12:
  %r204 = load i32, i32* @ptr
  %r205 = sub i32 %r204, 1
  store i32 %r205, i32* @ptr
  br label %bb14

bb13:
  br label %bb14

bb14:
  %r206 = icmp eq i32 %r199, 43
  br i1 %r206, label %bb15, label %bb16

bb15:
  %r207 = load i32, i32* @ptr
  %r135 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r207
  %r208 = load i32, i32* %r135
  %r209 = add i32 %r208, 1
  %r210 = load i32, i32* @ptr
  %r139 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r210
  store i32 %r209, i32* %r139
  br label %bb17

bb16:
  br label %bb17

bb17:
  %r211 = icmp eq i32 %r199, 45
  br i1 %r211, label %bb18, label %bb19

bb18:
  %r212 = load i32, i32* @ptr
  %r143 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r212
  %r213 = load i32, i32* %r143
  %r214 = sub i32 %r213, 1
  %r215 = load i32, i32* @ptr
  %r147 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r215
  store i32 %r214, i32* %r147
  br label %bb20

bb19:
  br label %bb20

bb20:
  %r216 = icmp eq i32 %r199, 46
  br i1 %r216, label %bb21, label %bb22

bb21:
  %r217 = load i32, i32* @ptr
  %r151 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r217
  %r218 = load i32, i32* %r151
  call void @putch(i32 %r218)
  br label %bb23

bb22:
  br label %bb23

bb23:
  %r219 = icmp eq i32 %r199, 44
  br i1 %r219, label %bb24, label %bb25

bb24:
  %r220 = call i32 @getch()
  %r221 = load i32, i32* @ptr
  %r157 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r221
  store i32 %r220, i32* %r157
  br label %bb26

bb25:
  br label %bb26

bb26:
  %r222 = icmp eq i32 %r199, 93
  br i1 %r222, label %bb30, label %bb28

bb30:
  %r223 = load i32, i32* @ptr
  %r161 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r223
  %r224 = load i32, i32* %r161
  %r225 = icmp ne i32 %r224, 0
  br i1 %r225, label %bb27, label %bb28

bb27:
  %r226 = add i32 1, 0
  br label %bb31

bb31:
  %r227 = phi i32 [ %r195, %bb27 ], [ %r231, %bb39 ]
  %r228 = phi i32 [ %r226, %bb27 ], [ %r241, %bb39 ]
  %r229 = icmp sgt i32 %r228, 0
  br i1 %r229, label %bb32, label %bb33

bb32:
  %r230 = sub i32 %r227, 1
  %r231 = add i32 %r230, 0
  %r169 = getelementptr i32, i32* %r113, i32 %r231
  %r232 = load i32, i32* %r169
  %r233 = add i32 %r232, 0
  %r234 = icmp eq i32 %r233, 91
  br i1 %r234, label %bb34, label %bb35

bb34:
  %r235 = sub i32 %r228, 1
  %r236 = add i32 %r235, 0
  br label %bb36

bb35:
  br label %bb36

bb36:
  %r237 = phi i32 [ %r236, %bb34 ], [ %r228, %bb35 ]
  %r238 = icmp eq i32 %r233, 93
  br i1 %r238, label %bb37, label %bb38

bb37:
  %r239 = add i32 %r237, 1
  %r240 = add i32 %r239, 0
  br label %bb39

bb38:
  br label %bb39

bb39:
  %r241 = phi i32 [ %r240, %bb37 ], [ %r237, %bb38 ]
  br label %bb31

bb33:
  br label %bb29

bb28:
  br label %bb29

bb29:
  %r242 = phi i32 [ %r227, %bb33 ], [ %r195, %bb28 ]
  %r243 = add i32 %r242, 1
  %r244 = add i32 %r243, 0
  br label %bb6

bb8:
  ret void
}

define i32 @main( ) {
bb40:
  call void @_sysy_starttime(i32 76)
  call void @read_program()
  call void @interpret(i32* @program)
  call void @putch(i32 10)
  call void @_sysy_stoptime(i32 80)
  ret i32 0
}

