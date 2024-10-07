import itertools

# 提供的数据字段列表
data_fields = [
    "fnd17_oxlcxspebq", "fnd17_shsoutbs", "fnd17_oxlcxspebq", "fnd28_value_05191q", "fnd17_oxlcxspebq",
    "fnd28_value_05192q", "fnd17_oxlcxspebq", "fnd28_value_05301q", "fnd17_oxlcxspebq", "fnd28_value_05302",
    "fnd17_pehigh", "fnd17_pelow", "fnd17_priceavg150day", "fnd17_priceavg200day", "fnd17_priceavg150day",
    "fnd17_priceavg50day", 'fnd17_priceavg200day', "fnd17_priceavg50day", "fnd17_pxedra", "fnd17_tbea", "fnd17_pxedra",
    'fnd28_newa3_value_18191a', "fnd17_pxedra", "fnd28_newa3_value_18198a", "fnd17_pxedra", "fnd28_value_02300a",
    "fnd17_pxedra", "fnd28_value_05302", "fnd17_pxedra", "mdl175_ebitda", "fnd17_pxedra", "mdl175_pain"
]

length = len(data_fields)

print(f"原始数据中总共有 {length} 个数据。")

unique_data_fields = list(set(data_fields))

length = len(unique_data_fields)

print(f"筛选之后数据中总共有 {length} 个数据。")
# 使用 itertools.combinations 获取所有不重复的两两组合
# combinations 将会是一个包含元组的列表，每个元组有两个元素，表示一个组合
combinations = list(itertools.combinations(unique_data_fields, 2))

# 创建 alpha 表达式的模板
# 对于每一个组合 (A, B)，将 A 和 B 插入到模板中以形成一个新的 alpha 表达式
# ts_zscore 函数可能是对时间序列进行标准化处理
# ts_regression 函数可能是对两个标准化后的时间序列进行回归分析
alpha_expressions = [
    f"ts_regression(ts_zscore({A}, 500), ts_zscore({B}, 500), 500)"  # 模板字符串
    for A, B in combinations  # 遍历所有的组合
]

# alpha_expressions 现在包含了所有根据 data_fields 生成的 alpha 表达式
# 总组合数就是 combinations 的长度
total_combinations = len(combinations)

# 输出结果
print(f"总共有 {total_combinations} 个组合。")
# 如果需要查看具体的 alpha 表达式，可以打印出来
# print(alpha_expressions)