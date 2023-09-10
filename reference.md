LLVM IR example

```
@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00"

define i32 @main() {
  %a = alloca i32
  store i32 5, i32* %a
  %t0 = load i32, i32* %a
  %t1 = add i32 %t0, 3
  store i32 %t1, i32* %a  
  %r12 = load i32, i32* %a
  call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 %r12)
  ret i32 0
}

declare i32 @printf(i8*, ...)
```
