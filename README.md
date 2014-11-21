PFTableViewCell-Static_Library
==============================

PFTableViewCell可完美实现动态高度的设置，列表上的控件会自动跟随列表高度的改变而自动调整相对位置

关键代码
------------------------------

//设置序号<br>
cell.indexPath = indexPath;<br>

//获取高度<br>
[PFTableViewCell heightAtIndexPath:indexPath];<br>

//设置高度<br>
[PFTableViewCell setHeight:cellModelOneHeight atIndexPath:indexPath];

注意
------------------------------

本代码目前为静态库的方式存在，若使用上出现错误，请与作者联系。<br>
当本库的使用者或者追随者超过100，作者考虑将本代码开放出来。
