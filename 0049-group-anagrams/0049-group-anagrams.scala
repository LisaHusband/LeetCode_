object Solution {
  def groupAnagrams(strs: Array[String]): List[List[String]] = {
    // 每个字母对应一个质数，注意索引从 0 到 25 分别表示 a 到 z
    val prime = Array(107, 3, 2, 5, 7, 11, 13, 17, 19, 23,
                      29, 31, 41, 43, 47, 53, 59, 61, 67,
                      71, 73, 79, 83, 89, 97, 101, 103)

    import scala.collection.mutable

    val map = mutable.Map[BigInt, List[String]]()

    for (s <- strs) {
      var key = BigInt(1) // 使用 BigInt 防止溢出
      for (c <- s) {
        val idx = c - 'a'
        key *= BigInt(prime(idx))
      }
      map.update(key, s :: map.getOrElse(key, Nil))
    }

    map.values.map(_.reverse).toList
  }
}
