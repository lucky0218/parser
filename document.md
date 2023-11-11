# Create a C-- lexical Analyzer

## 1. list of token types
### 1.1. keyword
+   `int, long, double, return, if, else, while, for, break, continue, void, struct, typedef, enum, switch, case, default, goto, const, static, extern, sizeof, register, union, do, signed, unsigned, char, short, float`

### 1.2. operator
+   `+ - * / %  = == !=  >=  <= && || ! & | ^  ~=   += -= *= /= %= &= |= ^= ~= `
+   暂未实现的运算符：`<< >> ++ -- ? : -> < > <<= >>= <= >=`
  
### 1.3. separator
+   `; ,  ( ) [ ] { }  `
+   暂未实现的分隔符: `< >`

### 1.4. number literal
+   `123, 123.456, 2E-4, `
+   暂未实现的数字常量: ` 0x 0 0b `
  
### 1.5. string literal
+   `"hello world"`

### 1.6. identifier
+  `__it`




## 2. usage
### 2.1 how to build
+ using Visual Studio 2019 and above

### 2.2 where to put the input file
+ /parser/sec/test.in