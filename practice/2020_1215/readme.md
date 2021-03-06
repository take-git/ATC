# 作用と副作用のお話
名前は聞いたことがあるが、実際なんなのかと言われると答えに窮するものがある。作用と副作用についてちゃんと学んでまとめようと思う。  
何故こんなことを思ったかというと、for文の中で登場するインクリメント演算子について、後置と前置でどう違うのかをclearに説明できないと感じたためである。

## インクリメント演算子の前置・後置記法の違い
```cpp
// 後置
for(int i = 0; i < 10; i++){
    // 処理
}

// 前置
for(int i = 0; i < 10; ++i){
    // 処理
}
```

上記の2つの処理の違いはなんだろうか？結論からいうと、ない。頭の片隅にあったprintする際に出力が変わる問題をググってみたところ、以下のような記事が大量に出てきた。  
- [インクリメント演算子とデクリメント演算子](https://www.javadrive.jp/start/ope/index6.html)

この記事はJavaを対象に書かれた記事だが、大差ないと思われるのでこのまま参考にさせてもらう。また、デクリメント演算子は減算をするだけで同じ挙動を示すため省く。
```java
int num = 5;
num++;

System.out.println(num);  // 6 が出力される
```
想像通りだろう。では以下はどうだろう？

```java
int x = 5;
int y;

y = x++;
System.out.println(x);  // 6
System.out.println(y);  // 5

```
yが5を出力するのは少し不思議な感じがする。代入のタイミングが直感とズレているのがわかるだろうか？**後置記法の場合、代入演算が先に評価され、その後にxがインクリメントされる。**  
上のコードは以下のコードと等価であることがわかる。
```java
y = x++;

というのは

y = x;
x = x + 1;

と同じ
```

それに対して前置き
```java
y = ++x;

というのは

x = x + 1;
y = x;

と同じ
```

とまあ、ほぼほぼコピペみたいな話をしたあとで...

## 本題：副作用とは何か
[Wikipedia](https://ja.wikipedia.org/wiki/%E5%89%AF%E4%BD%9C%E7%94%A8_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%A0)#:~:text=%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0%E3%81%AB%E3%81%8A%E3%81%84%E3%81%A6%E3%80%81%E5%BC%8F%E3%81%AE%E8%A9%95%E4%BE%A1,%E3%81%95%E3%81%9B%E3%82%8B%E4%BD%9C%E7%94%A8%E3%82%92%E5%89%AF%E4%BD%9C%E7%94%A8%E3%81%A8%E3%81%84%E3%81%86%E3%80%82)先生には以下のようにある。
> プログラミングにおいて、式の評価による作用には、主たる作用とそれ以外の副作用(side effect)とがある[1][2]。 式は、評価値を得ること(※関数では「引数を受け取り値を返す」と表現する）が主たる作用とされ、それ以外のコンピュータの論理的状態(ローカル環境以外の状態変数の値)を変化させる作用を副作用という[3][4][5]。

なるほどよくわかる説明だ。その処理の目的と、それを達成する上で変わっちゃう他の要素って感じか。
関数は基本的に返り値を持っており、関数の作用は基本的に値を返すことらしい。値を返すに当たってどこかのリソースに変更が加えられることがある。例えば、ある変数に5を加算し返すadd関数を考えてみよう。この時の作用と副作用はなんだろう？  

答えは変数に5が加算された「値を返す」ことが作用であり、変数の中身が書き換わってしまうことが副作用である。
ややこしく感じるかもしれないが、以下の処理には副作用がない。
```
double: x -> 2*x
例:
4 <- double: 2
```

関数が内部に状態を持ち、関数内のlocal変数を変更するだけで処理を終えてしまう場合は外部リソースにはなんら変更がない。したがって副作用はない。
その他、副作用と呼ばれるものには以下のものが該当する。
- 変数の値を変更する（上の例）
- ファイルに対して読み書きをする（I/0）
- プログラムの制御を変更する（ジャンプする）