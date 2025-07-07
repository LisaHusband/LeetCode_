import scala.util.control.Breaks._

object Solution {
  // 定义四个方向
  val DIRS = Array(Array(0, 1), Array(0, -1), Array(1, 0), Array(-1, 0))

  def exist(board: Array[Array[Char]], word: String): Boolean = {
    var result = false  // 用来记录是否找到单词
    var wordVar = word  // 使用 var 声明 word，允许重新赋值
    val cnt = scala.collection.mutable.Map[Char, Int]()

    // 统计 board 中字符的数量
    for (row <- board) {
      for (c <- row) {
        cnt(c) = cnt.getOrElse(c, 0) + 1
      }
    }

    // 优化一：检查 word 中字符的数量是否超过 board 中字符的数量
    val wordCnt = scala.collection.mutable.Map[Char, Int]()
    breakable {
      for (c <- wordVar) {
        wordCnt(c) = wordCnt.getOrElse(c, 0) + 1
        if (wordCnt(c) > cnt.getOrElse(c, 0)) {
          result = false  // 通过设置 result 来代替 return false
          break()  // 提前退出
        }
      }
    }

    // 优化二：如果最后一个字符的数量比第一个字符的数量少，则反转 word
    if (cnt.getOrElse(wordVar.last, 0) < cnt.getOrElse(wordVar.head, 0)) {
      wordVar = wordVar.reverse  // 这里改为 var，所以可以重新赋值
    }

    val m = board.length
    val n = board(0).length

    // 定义回溯函数
    def dfs(i: Int, j: Int, k: Int): Unit = {
      if (board(i)(j) != wordVar(k)) {
        return
      }
      if (k + 1 == wordVar.length) {
        result = true
        return
      }

      val temp = board(i)(j)
      board(i)(j) = '0'  // 标记当前位置已访问

      breakable {
        for (dir <- DIRS) {
          val x = i + dir(0)
          val y = j + dir(1)
          if (x >= 0 && x < m && y >= 0 && y < n) {
            dfs(x, y, k + 1)
            if (result) break()  // 如果找到了，提前退出
          }
        }
      }

      board(i)(j) = temp  // 恢复现场
    }

    // 遍历每个起始位置，尝试匹配单词
    breakable {
      for (i <- 0 until m) {
        for (j <- 0 until n) {
          if (board(i)(j) == wordVar(0) && !result) {
            dfs(i, j, 0)
          }
          if (result) break()  // 如果找到了，提前退出
        }
      }
    }

    result  // 返回最终的结果
  }
}
