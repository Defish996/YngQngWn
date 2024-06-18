//2288. 价格减免 模拟 取单词 + 替换


class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int wordSize = sentence.size();
        istringstream s(sentence);//将每个单词取出来
        string word;
        string ans;
        while(s >> word)//单词取出来直到末尾
        {
            if(word[0]=='$')//是金额
            {
                string num;//将金额存入string
                for(auto& c : word)
                {
                    if(isdigit(c))
                    {
                        num.push_back(c);
                    }
                }
                if(num.size() != word.size() - 1 || num.size() == 0)
                {
                    goto end;
                }
                long long number = stoll(num);
                double result = static_cast<double>(number)* (1 - (double)discount / 100);

                // 使用 ostringstream 来格式化输出
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(2) << result;

                // 将格式化后的字符串存储到 word 中
                word = '$' + oss.str();
            }
            end:
            ans += word + ' ';
        }
        ans.pop_back();
        return ans;
    }
};