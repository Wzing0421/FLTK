vs配置FLTK库
在VS中，选择项目菜单，在下拉菜单中选择属性。在属性对话框中，在左侧的菜单中点击链接器文件夹。在扩展子菜单中点击输入。
在右侧的附属依赖项文本域中，输入：fltkd.lib; wsock32.lib; comctl32.lib; fltkjpegd.lib;fltkimagesd.lib; 在忽略特定库文本域中，输入：libcd.lib