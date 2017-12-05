from splinter import Browser
import time
import schedule
#b = Browser("C:\selenium_driver_chrome\chromedriver.exe")
schedule.
b = Browser('chrome', executable_path='C:\selenium_driver_chrome\chromedriver.exe')
url = "http://24h.pchome.com.tw/prod/DEBLA7-A9006Q0WR?q=/S/DXAR7J"
#url = "http://192.168.8.80"
b.visit(url)
time.sleep(2)
b.find_by_xpath('//select[@class="spec"]//option[@value="DEBLA7-A9006Q0WR-002"]').click()
b.find_by_xpath('//button[@accesskey="I"]').click()
b.click_link_by_href('http://shopping.pchome.com.tw/?mod=store&func=choice_buy&page_url=shopping&NO=D&C=D')
b.find_by_id('loginEmail').fill('leo79523@hotmail.com')
b.find_by_id('loginPwd').fill('pagedown523')
b.find_by_xpath('//span[@class="ui-btn b-submit"]').click()
