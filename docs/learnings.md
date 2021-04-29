# C

- stdio の各種関数はよしなに buffer してくれて便利！
- システムコールの世界では、STDIN_FILENO/STDOUT_FILENO という変数で、素のファイルディスクリプタを扱う。
  - open(2), close(2), read(2), write(2)
- stdio では、stdin/stdout という変数で、buffer 機能をもったファイルディスクリプタのラッパーである FILE 型の値を扱う。
  - fopen(3), fclose(3), fread(3), fwrite(3)
- stdio の操作と素のファイルディスクリプタの操作を混在させると、stdio の buffer を介する/介さない処理が混在することになって困ることがある。
  - fileno(3) / fileopen(3) で `int fd <=> FILE *stream` の変換を使ってよしなに揃えるべし

|          | 任意の指定したストリーム | 標準入出力      |
| -------- | ------------------------ | --------------- |
| 文字単位 | fgetc/fputc              | getchar/putchar |
| 行単位   | fgets/fputs              | ~~gets~~/puts   |

- 「gets()は buffer overflow を起こすリスクがあるので絶対に使ってはダメ」っていうの、そういう関数がふつうに使える状態で存在しているってのが、C 言語って恐ろしい世界だなあ...とおもう。

# sh

- ストリームをパイプでリレーしていて、改行とかが処理するデータの区切れ目になる。それが概ね配列に相当するってことだと理解した。だいぶ発想が違うな。
- 標準入力は不可で引数しか受けつけないコマンドに対しては以下で渡せる
  - `... | xargs -I{} -L1 COMMAND {}`

# Makefile

- 初めての人間にとってスッと入ってくる情報が少ない印象
- [ここ](http://quruli.ivory.ne.jp/document/make_3.79.1/make-jp_toc.html#SEC_Contents)がいちばんよかった
- 知ったこと
  - 基本的な構造
    - target / dependency / rule
  - 組み込み変数
    - `$<`, `$@` etc.
  - 組み込み関数
    - `wildcard`, `dirname` etc.
    - `$(FUNC ARGS)`と書いてつかう
    - シェルコマンドの結果を変数に格納したいときは、shell 関数をつかって`HOGE = $(shell echo ...)`のように書ける
      - ルールではシェルコマンドを直接記述できるので混同しないように
    - 文字列（のリスト）をパターンに基づいて変換できる`patsubst`があるが、以下の簡易的な記法と等価
      - ` $(VAR:PATTERN=REPLACEMENT)`
  - パターンルール
    - ターゲット名で`%`を用いたパターンマッチングができる
    - `foo/bar/baz.c`に対して`%.c`を当てると、`%`には`foo/bar/baz`が入ることに注意（`baz`ではない）
    - サフィックスルールは old-fashioned なのでパターンルールをつかう
- 動くときもちい！！！！
- 複雑なことをやろうとすると書くのも読むのもつらそう
- make のバージョンの違いとかでハマるとつらそう