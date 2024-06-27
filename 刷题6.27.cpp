//leetcode2734. 执行子串操作后的字典序最小字符串
//根据题意，把 a 替换成 z 会让字典序变大，所以被替换的子串不能包含 a。反过来，如果子串不含 a，那么对其操作可以让 s 字典序变小。
//从左到右找到第一个不等于 a 的字符 s[i]，然后从 i 开始，把每个字符都减一，直到遍历结束或者遇到了 a。例如 abca 操作中间的子串 bc，得到答案 aaba。
//细节：如果 s 全为 a，由于题目要求必须操作一次，可以把最后一个 a 改成 z。


class Solution {

	public:

		string smallestString(string s) {

			int n = s.length();

			for (int i = 0; i < n; i++) {

				if (s[i] > 'a') {

					// 继续向后遍历

					for (; i < n && s[i] > 'a'; i++) {

						s[i]--;

					}

					return s;

				}

			}

			// 所有字母均为 a

			s.back() = 'z';

			return s;

		}

};
