## 動的計画法 - 編集距離
[レーベンシュタイン距離](https://ja.wikipedia.org/wiki/%E3%83%AC%E3%83%BC%E3%83%99%E3%83%B3%E3%82%B7%E3%83%A5%E3%82%BF%E3%82%A4%E3%83%B3%E8%B7%9D%E9%9B%A2#:~:text=%E7%B7%A8%E9%9B%86%E8%B7%9D%E9%9B%A2%EF%BC%88%E3%81%B8%E3%82%93%E3%81%97%E3%82%85%E3%81%86%E3%81%8D%E3%82%87,%E5%9B%9E%E6%95%B0%E3%81%A8%E3%81%97%E3%81%A6%E5%AE%9A%E7%BE%A9%E3%81%95%E3%82%8C%E3%82%8B%E3%80%82)

お馴染みのやつ。計算量はO(mn)らしい。かなり効率がよい。(mとnはそれぞれ比較する文字の文字数)
競技プログラミング的には以下のような問題を考える。
```
２つの文字S,Tが与えられます。Sに以下の３通りの操作を繰り返し施す事でTに変換したいものとします。
そのような一連の操作のうち、操作回数の最小値を求めてください。

```

また別問題として区間分割の仕方を最適化する問題に関してコーディングする。