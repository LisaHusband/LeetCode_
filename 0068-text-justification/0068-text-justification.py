class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = []
        current_words = []  # 当前行的单词
        current_length = 0  # 当前行单词的总长度

        for word in words:
            # 判断当前单词加入后是否超过了 maxWidth
            if current_length + len(word) + len(current_words) > maxWidth:
                # 如果超过了，先处理当前行
                # 计算空格数量
                spaces = maxWidth - current_length
                if len(current_words) == 1:
                    # 如果当前行只有一个单词，所有空格都放在单词后面
                    res.append(current_words[0] + " " * spaces)
                else:
                    # 分配空格到单词之间
                    even_space = spaces // (len(current_words) - 1)
                    extra_space = spaces % (len(current_words) - 1)
                    line = current_words[0]
                    for i in range(1, len(current_words)):
                        # 每个单词之间放 even_space 个空格
                        # 如果还有多余空格 extra_space，放在左边的单词之间
                        if i <= extra_space:
                            line += " " * (even_space + 1) + current_words[i]
                        else:
                            line += " " * even_space + current_words[i]
                    res.append(line)
                
                # 重置当前行
                current_words = [word]
                current_length = len(word)
            else:
                # 如果没有超过，继续加单词
                current_words.append(word)
                current_length += len(word)

        # 处理最后一行，左对齐
        last_line = " ".join(current_words)
        res.append(last_line + " " * (maxWidth - len(last_line)))

        return res