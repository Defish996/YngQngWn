//2806. 取整购买后的账户余额


class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int sum = purchaseAmount/10;
        return (purchaseAmount % 10) >= 5 ? (100 - (++sum)*10) : (100 - sum * 10);
        
    }
};