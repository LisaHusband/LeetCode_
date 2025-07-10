func isPalindrome(s string) bool {
    // 将字符串中的非字母数字字符移除，并转换为小写
	var filteredString []rune
	for _, char := range s {
		// 判断字符是否为字母或数字
		if unicode.IsLetter(char) || unicode.IsDigit(char) {
			filteredString = append(filteredString, unicode.ToLower(char))
		}
	}

	// 判断处理后的字符串是否是回文
	for i := 0; i < len(filteredString)/2; i++ {
		if filteredString[i] != filteredString[len(filteredString)-1-i] {
			return false
		}
	}

	return true
}