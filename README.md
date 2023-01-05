# one_commits__Samples_calc_nth_max1

This is a sample so that I can commit this to the GitHub.

## 1. Questions

m人の名前と点数が渡される。その中からn番目に点数が大きい人名と点数を表示するプログラムを組め。
ただし、異常系に関しては考慮しないものとする。

## 2. Conditions

```
3≦m≦50
1≦n≦m
3≦point_{i}≦50
3≦|name_{i}|≦20
```

## 3. Inputs and Outputs

### 3.1. Inputs

```
m n
name_1 point_1
name_2 point_2
name_3 point_3
...
name_m age_m
```

一行目に人数mとn番目の指定が半角スペースを区切り文字として渡され、
二行目以降は人名name_{i}と点数point_{i}も同様に半角スペースを区切り文字として渡される。

### 3.2. Outputs

```
name point
```

点数がN番目に大きい人名と点数を、半角スペースを区切り文字として表示する。

### 3.3. Examples

#### 3.3.1. Inputs 1

```
10 3
Taro 65
Jiro 70
Sakura 83
Tsubaki 64
Atsushi 84
Kenji 85
Megumi 69
Tomomi 59
Takashi 49
Tomoko 80
```
#### 3.3.2. Outputs 1

```
Sakura 83
```

※ Inputs 1 は input1.txt, Output 1 は output1.txt に記述されているとする。
