## 動的計画法の例題

### AtcoderEducational DP Contest A - Frog 1
* *  
N個のの足場があって、i(=0, 1, ..., N-1)番目の足場の高さはhiで与えらます。最初0番目の足場に帰るがいて、以下のいずれかの行動を繰り返してN-1番目の足場を目指します。
- 足場iから足場i+1へと移動する（コストは|hi - hi+1|）
- 足場iから足場i+2へと移動する（コストは|hi - hi+2|）
カエルがN-1番目の足場にたどり着くまでに要するコストの総和の最小値を求めてください。
* * 