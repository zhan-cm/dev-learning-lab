name="黑马"
stock_price=19.99
stock_code="003032"
stock_price_daily_growth_factor=1.2
growth_days=7
finally_price=stock_price*stock_price_daily_growth_factor**growth_days
print(f"公司名为{name},最终的股价为：{finally_price}")
print("最终的股价为%.2f"% finally_price)