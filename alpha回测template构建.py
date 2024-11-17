from main import * 
s = login()
fo_tracker = get_alphas("11-15", "11-18", 1.58, 1, "USA", 310, "submit") #[)

print('开始check可用的alpha : ')

stone_bag = []
for alpha in fo_tracker:
    stone_bag.append(alpha[0])
print(len(stone_bag))
gold_bag = []
check_submission(stone_bag, gold_bag, 0)
print(gold_bag)


# 
view_alphas(gold_bag)


## 下述是关于依据template构建的alpha
from main import * 
group_ops = ["group_neutralize", "group_rank", "group_normalize", "group_scale", "group_zscore"]
s = login()
df = get_datafields(s, dataset_id = 'option4', region='USA', universe='TOP3000', delay=1)
# print(df)
grp_opt_list = df[df['type'] == "MATRIX"]["id"].tolist()
pc_fields = process_datafields(df, "matrix")
# print(pc_fields)

# df = get_datafields(s, dataset_id='other429', region='USA', universe='TOP3000', delay=1)
# vec_list = df[df['type'] == "VECTOR"]["id"].tolist()# 获取fields
# print(vec_list)
# print(process_datafields(df, "vector"))

# # 示例使用
# pos_group, neg_group = get_pos_neg(vec_list)

# print("Positive suffix group:", pos_group)
# print("Negative suffix group:", neg_group)

def get_call_put(strings):
    # 初始化两个空列表用于存储分组后的字符串
    put_delta_list = []
    call_delta_list = []
    put_theta_list = []
    call_theta_list = []
    put_gamma_list = []
    call_gamma_list = []
    # 遍历输入的字符串列表
    for s in strings:
        # 检查字符串中是否包含 "put" 或 "call"
        if 'put_delta' in s.lower():  # 使用 lower() 确保匹配不受大小写影响
            put_delta_list.append(s)
        elif 'call_delta' in s.lower():  # 使用 lower() 确保匹配不受大小写影响
            call_delta_list.append(s)
        elif 'put_theta' in s.lower():  # 使用 lower() 确保匹配不受大小写影响
            put_theta_list.append(s)
        elif 'call_theta' in s.lower():  # 使用 lower() 确保匹配不受大小写影响
            call_theta_list.append(s)
        elif 'put_gamma' in s.lower():  # 使用 lower() 确保匹配不受大小写影响
            put_gamma_list.append(s)
        elif 'call_gamma' in s.lower():  # 使用 lower() 确保匹配不受大小写影响
            call_gamma_list.append(s)
        
    
    # 返回包含两个分组列表的元组
    return put_delta_list, call_delta_list, put_theta_list, call_theta_list, put_gamma_list, call_gamma_list 

put_delta_list, call_delta_list, put_theta_list, call_theta_list, put_gamma_list, call_gamma_list = get_call_put(grp_opt_list)

print("put group:", len(put_delta_list))
print("call group:", len(call_delta_list))
print("put theta list:", len(put_theta_list))
print("call theta list:", len(call_theta_list))
print("put gamma list:", len(put_gamma_list))
print("call gamma list:", len(call_gamma_list))

def assemble_expression(group_ops, put_list, call_list, region):
    output = []
    vectors = ["cap"] 
    
    chn_group_13 = ['pv13_h_min2_sector', 'pv13_di_6l', 'pv13_rcsed_6l', 'pv13_di_5l', 'pv13_di_4l', 
                        'pv13_di_3l', 'pv13_di_2l', 'pv13_di_1l', 'pv13_parent', 'pv13_level']
    
    
    chn_group_1 = ['sta1_top3000c30','sta1_top3000c20','sta1_top3000c10','sta1_top3000c2','sta1_top3000c5']
    
    chn_group_2 = ['sta2_top3000_fact4_c10','sta2_top2000_fact4_c50','sta2_top3000_fact3_c20']
 
    chn_group_7 = [ ] # 'oth171_region_sector_long_d1_sector','oth171_region_sector_short_d1_sector', 
                   
    
    hkg_group_13 = ['pv13_10_f3_g2_minvol_1m_sector', 'pv13_10_minvol_1m_sector', 'pv13_20_minvol_1m_sector', 
                    'pv13_2_minvol_1m_sector', 'pv13_5_minvol_1m_sector', 'pv13_1l_scibr', 'pv13_3l_scibr',
                    'pv13_2l_scibr', 'pv13_4l_scibr', 'pv13_5l_scibr']
    
    hkg_group_1 = ['sta1_allc50','sta1_allc5','sta1_allxjp_513_c20','sta1_top2000xjp_513_c5']
    
    hkg_group_2 = ['sta2_all_xjp_513_all_fact4_c10','sta2_top2000_xjp_513_top2000_fact3_c10',
                   'sta2_allfactor_xjp_513_13','sta2_top2000_xjp_513_top2000_fact3_c20']
    
    hkg_group_8 = ['oth455_relation_n2v_p10_q50_w5_kmeans_cluster_5',
                     'oth455_relation_n2v_p10_q50_w4_kmeans_cluster_10',
                     'oth455_relation_n2v_p10_q50_w1_kmeans_cluster_20',
                     'oth455_partner_n2v_p50_q200_w4_kmeans_cluster_5', 
                     'oth455_partner_n2v_p10_q50_w4_pca_fact3_cluster_10',
                     'oth455_customer_n2v_p50_q50_w1_kmeans_cluster_5']
    
    twn_group_13 = ['pv13_2_minvol_1m_sector','pv13_20_minvol_1m_sector','pv13_10_minvol_1m_sector',
                    'pv13_5_minvol_1m_sector','pv13_10_f3_g2_minvol_1m_sector','pv13_5_f3_g2_minvol_1m_sector',
                    'pv13_2_f4_g3_minvol_1m_sector']
    
    twn_group_1 = ['sta1_allc50','sta1_allxjp_513_c50','sta1_allxjp_513_c20','sta1_allxjp_513_c2',
                   'sta1_allc20','sta1_allxjp_513_c5','sta1_allxjp_513_c10','sta1_allc2','sta1_allc5']
    
    twn_group_2 = ['sta2_allfactor_xjp_513_0','sta2_all_xjp_513_all_fact3_c20',
                   'sta2_all_xjp_513_all_fact4_c20','sta2_all_xjp_513_all_fact4_c50']
    
    twn_group_8 = ['oth455_relation_n2v_p50_q200_w1_pca_fact1_cluster_20',
                     'oth455_relation_n2v_p10_q50_w3_kmeans_cluster_20',
                     'oth455_relation_roam_w3_pca_fact2_cluster_5',
                     'oth455_relation_n2v_p50_q50_w2_pca_fact2_cluster_10', 
                     'oth455_relation_n2v_p10_q200_w5_pca_fact2_cluster_20',
                     'oth455_relation_n2v_p50_q50_w5_kmeans_cluster_5']
    
    usa_group_13 = ['pv13_h_min2_3000_sector','pv13_r2_min20_3000_sector','pv13_r2_min2_3000_sector',
                    'pv13_r2_min2_3000_sector', 'pv13_h_min2_focused_pureplay_3000_sector']
    
    usa_group_1 = ['sta1_top3000c50','sta1_allc20','sta1_allc10','sta1_top3000c20','sta1_allc5']
    
    usa_group_2 = ['sta2_top3000_fact3_c50','sta2_top3000_fact4_c20','sta2_top3000_fact4_c10']
    
    usa_group_3 = ['sta3_2_sector', 'sta3_3_sector', 'sta3_news_sector', 'sta3_peer_sector',
                   'sta3_pvgroup1_sector', 'sta3_pvgroup2_sector', 'sta3_pvgroup3_sector', 'sta3_sec_sector']
    
    usa_group_4 = ['rsk69_01c_1m', 'rsk69_57c_1m', 'rsk69_02c_2m', 'rsk69_5c_2m', 'rsk69_02c_1m',
                   'rsk69_05c_2m', 'rsk69_57c_2m', 'rsk69_5c_1m', 'rsk69_05c_1m', 'rsk69_01c_2m']
    
    usa_group_5 = ['anl52_2000_backfill_d1_05c', 'anl52_3000_d1_05c', 'anl52_3000_backfill_d1_02c', 
                   'anl52_3000_backfill_d1_5c', 'anl52_3000_backfill_d1_05c', 'anl52_3000_d1_5c']
    
    usa_group_6 = ['mdl10_group_name']
    
    usa_group_7 = []
    
    usa_group_8 = ['oth455_competitor_n2v_p10_q50_w1_kmeans_cluster_10',
                     'oth455_customer_n2v_p10_q50_w5_kmeans_cluster_10',
                     'oth455_relation_n2v_p50_q200_w5_kmeans_cluster_20',
                     'oth455_competitor_n2v_p50_q50_w3_kmeans_cluster_10', 
                     'oth455_relation_n2v_p50_q50_w3_pca_fact2_cluster_10', 
                     'oth455_partner_n2v_p10_q50_w2_pca_fact2_cluster_5',
                     'oth455_customer_n2v_p50_q50_w3_kmeans_cluster_5',
                     'oth455_competitor_n2v_p50_q200_w5_kmeans_cluster_20']
    
    
    asi_group_13 = ['pv13_20_minvol_1m_sector', 'pv13_5_f3_g2_minvol_1m_sector', 'pv13_10_f3_g2_minvol_1m_sector',
                    'pv13_2_f4_g3_minvol_1m_sector', 'pv13_10_minvol_1m_sector', 'pv13_5_minvol_1m_sector']
    
    asi_group_1 = ['sta1_allc50', 'sta1_allc10', 'sta1_minvol1mc50','sta1_minvol1mc20',
                   'sta1_minvol1m_normc20', 'sta1_minvol1m_normc50']
    
    asi_group_8 = ['oth455_partner_roam_w3_pca_fact1_cluster_5',
                   'oth455_relation_roam_w3_pca_fact1_cluster_20',
                   'oth455_relation_roam_w3_kmeans_cluster_20',
                   'oth455_relation_n2v_p10_q200_w5_pca_fact1_cluster_20',
                   'oth455_relation_n2v_p10_q200_w5_pca_fact1_cluster_20',
                   'oth455_competitor_n2v_p10_q200_w1_kmeans_cluster_10']
    
    jpn_group_1 = ['sta1_alljpn_513_c5', 'sta1_alljpn_513_c50', 'sta1_alljpn_513_c2', 'sta1_alljpn_513_c20']
    
    jpn_group_2 = ['sta2_top2000_jpn_513_top2000_fact3_c20', 'sta2_all_jpn_513_all_fact1_c5',
                   'sta2_allfactor_jpn_513_9', 'sta2_all_jpn_513_all_fact1_c10']
    
    jpn_group_8 = ['oth455_customer_n2v_p50_q50_w5_kmeans_cluster_10', 
                   'oth455_customer_n2v_p50_q50_w4_kmeans_cluster_10', 
                   'oth455_customer_n2v_p50_q50_w3_kmeans_cluster_10', 
                   'oth455_customer_n2v_p50_q50_w2_kmeans_cluster_10',
                   'oth455_customer_n2v_p50_q200_w5_kmeans_cluster_10',
                   'oth455_customer_n2v_p50_q200_w5_kmeans_cluster_10']
    
    jpn_group_13 = ['pv13_2_minvol_1m_sector', 'pv13_2_f4_g3_minvol_1m_sector', 'pv13_10_minvol_1m_sector',
                    'pv13_10_f3_g2_minvol_1m_sector', 'pv13_all_delay_1_parent', 'pv13_all_delay_1_level']
    
    kor_group_13 = ['pv13_10_f3_g2_minvol_1m_sector', 'pv13_5_minvol_1m_sector', 'pv13_5_f3_g2_minvol_1m_sector',
                    'pv13_2_minvol_1m_sector', 'pv13_20_minvol_1m_sector', 'pv13_2_f4_g3_minvol_1m_sector']
    
    kor_group_1 = ['sta1_allc20','sta1_allc50','sta1_allc2','sta1_allc10','sta1_minvol1mc50',
                   'sta1_allxjp_513_c10', 'sta1_top2000xjp_513_c50']
    
    kor_group_2 =['sta2_all_xjp_513_all_fact1_c50','sta2_top2000_xjp_513_top2000_fact2_c50',
                  'sta2_all_xjp_513_all_fact4_c50','sta2_all_xjp_513_all_fact4_c5']
    
    kor_group_8 = ['oth455_relation_n2v_p50_q200_w3_pca_fact3_cluster_5',
                     'oth455_relation_n2v_p50_q50_w4_pca_fact2_cluster_10',
                     'oth455_relation_n2v_p50_q200_w5_pca_fact2_cluster_5',
                     'oth455_relation_n2v_p50_q200_w4_kmeans_cluster_10', 
                     'oth455_relation_n2v_p10_q50_w1_kmeans_cluster_10', 
                     'oth455_relation_n2v_p50_q50_w5_pca_fact1_cluster_20']
    
    eur_group_13 = ['pv13_5_sector', 'pv13_2_sector', 'pv13_v3_3l_scibr', 'pv13_v3_2l_scibr', 'pv13_2l_scibr',
                    'pv13_52_sector', 'pv13_v3_6l_scibr', 'pv13_v3_4l_scibr', 'pv13_v3_1l_scibr']
    
    eur_group_1 = ['sta1_allc10', 'sta1_allc2', 'sta1_top1200c2', 'sta1_allc20', 'sta1_top1200c10']
    
    eur_group_2 = ['sta2_top1200_fact3_c50','sta2_top1200_fact3_c20','sta2_top1200_fact4_c50']
    
    eur_group_3 = ['sta3_6_sector', 'sta3_pvgroup4_sector', 'sta3_pvgroup5_sector']
    
    eur_group_7 = []
    
    eur_group_8 = ['oth455_relation_n2v_p50_q200_w3_pca_fact1_cluster_5',
                     'oth455_competitor_n2v_p50_q200_w4_kmeans_cluster_20',
                     'oth455_competitor_n2v_p50_q200_w5_pca_fact1_cluster_10', 
                     'oth455_competitor_roam_w4_pca_fact2_cluster_20', 
                     'oth455_relation_n2v_p10_q200_w2_pca_fact2_cluster_20', 
                     'oth455_competitor_roam_w2_pca_fact3_cluster_20']
    
    glb_group_13 = ["pv13_10_f2_g3_sector", "pv13_2_f3_g2_sector", "pv13_2_sector", "pv13_52_all_delay_1_sector"]
    
    glb_group_3 = ['sta3_2_sector', 'sta3_3_sector', 'sta3_news_sector', 'sta3_peer_sector',
                   'sta3_pvgroup1_sector', 'sta3_pvgroup2_sector', 'sta3_pvgroup3_sector', 'sta3_sec_sector']
    
    glb_group_1 = ['sta1_allc20', 'sta1_allc10', 'sta1_allc50', 'sta1_allc5']
    
    glb_group_2 = ['sta2_all_fact4_c50', 'sta2_all_fact4_c20', 'sta2_all_fact3_c20', 'sta2_all_fact4_c10']
    
    glb_group_13 = ['pv13_2_sector', 'pv13_10_sector', 'pv13_3l_scibr', 'pv13_2l_scibr', 'pv13_1l_scibr',
                    'pv13_52_minvol_1m_all_delay_1_sector','pv13_52_minvol_1m_sector','pv13_52_minvol_1m_sector']
    
    glb_group_7 = []  
    
    glb_group_8 = ['oth455_relation_n2v_p10_q200_w5_kmeans_cluster_5',
                     'oth455_relation_n2v_p10_q50_w2_kmeans_cluster_5',
                     'oth455_relation_n2v_p50_q200_w5_kmeans_cluster_5', 
                     'oth455_customer_n2v_p10_q50_w4_pca_fact3_cluster_20', 
                     'oth455_competitor_roam_w2_pca_fact1_cluster_10', 
                     'oth455_relation_n2v_p10_q200_w2_kmeans_cluster_5']
    
    amr_group_13 = ['pv13_4l_scibr', 'pv13_1l_scibr', 'pv13_hierarchy_min51_f1_sector',
                    'pv13_hierarchy_min2_600_sector', 'pv13_r2_min2_sector', 'pv13_h_min20_600_sector']
    
    amr_group_3 = ['sta3_news_sector', 'sta3_peer_sector', 'sta3_pvgroup1_sector', 'sta3_pvgroup2_sector',
                   'sta3_pvgroup3_sector']
    
    amr_group_8 = ['oth455_relation_roam_w1_pca_fact2_cluster_10', 
                   'oth455_competitor_n2v_p50_q50_w4_kmeans_cluster_10', 
                   'oth455_competitor_n2v_p50_q50_w3_kmeans_cluster_10', 
                   'oth455_competitor_n2v_p50_q50_w2_kmeans_cluster_10', 
                   'oth455_competitor_n2v_p50_q50_w1_kmeans_cluster_10',
                   'oth455_competitor_n2v_p50_q200_w5_kmeans_cluster_10']
    
    group_3 = []
    
    bps_group = "bucket(rank(fnd28_value_05480/close), range='0.2, 1, 0.2')"
    cap_group = "bucket(rank(cap), range='0.1, 1, 0.1')"
    sector_cap_group = "bucket(group_rank(cap,sector),range='0,1,0.1')"
    vol_group = "bucket(rank(ts_std_dev(ts_returns(close,1),20)),range = '0.1,1,0.1')"
    groups = ["market","sector", "industry", "subindustry", bps_group, cap_group, sector_cap_group]
    
    regions = []

    if region == "CHN":
        regions += chn_group_13 + chn_group_1 + chn_group_2  
    if region == "TWN":
        regions += twn_group_13 + twn_group_1 + twn_group_2 + twn_group_8 
    if region == "ASI":
        regions += asi_group_13 + asi_group_1 + asi_group_8 
    if region == "USA":
        regions += usa_group_13 + usa_group_1 + usa_group_2 + usa_group_3 + usa_group_4 + usa_group_8 + group_3 
        regions += usa_group_5 + usa_group_6 + usa_group_7
    if region == "HKG":
        regions += hkg_group_13 + hkg_group_1 + hkg_group_2 + hkg_group_8
    if region == "KOR":
        regions += kor_group_13 + kor_group_1 + kor_group_2 + kor_group_8
    if region == "EUR": 
        regions += eur_group_13 + eur_group_1 + eur_group_2 + eur_group_3 + eur_group_8 +  eur_group_7 + group_3 
    if region == "GLB":
        regions += glb_group_13 + glb_group_8 + glb_group_3 + glb_group_1 + glb_group_7 + group_3
    if region == "AMR":
        regions += amr_group_3 + amr_group_13
    if region == "JPN":
        regions += jpn_group_1 + jpn_group_2 + jpn_group_13 + jpn_group_8
    # 初始化一个空数组来存储最终的表达式
    expressions = []
    
    # 遍历group_operator数组
    for op in group_ops:
        # 遍历put_greek和call_greek数组
        for put, call in zip(put_list, call_list):
            # 构建表达式的第一部分：put_greek - call_greek
            expression_part = f"{put} - {call}"
            
            # 遍历grouping_data数组
            for data in regions:
                # 将三部分组合成一个完整的表达式
                full_expression = f"{op}({expression_part}, {data})"
                # 将完整的表达式添加到结果数组中
                expressions.append(full_expression)
    
    # 返回包含所有表达式的数组
    return expressions

alpha_list = assemble_expression(group_ops, put_delta_list, call_delta_list, "USA")
# print(alpha_list)
print(len(alpha_list))

init_decay = 6
fo_alpha_list = []
for alpha in alpha_list:
    fo_alpha_list.append((alpha, init_decay))
print(len(fo_alpha_list))
print(fo_alpha_list[:5])


so_pools = load_task_pool(fo_alpha_list, 10, 9)
multi_simulate(so_pools, 'SUBINDUSTRY', 'USA', 'TOP3000', 4)
