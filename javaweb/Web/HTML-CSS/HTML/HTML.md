<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>HTML学习笔记</title>
</head>
<body>
    <h1>标题，分为h1-h6</h1>

    <p>段落</p>

    <a href="httpS//www/w3school.com.cn">这是链接</a>
    HTML 链接 - target 属性
    使用 Target 属性，你可以定义被链接的文档在何处显示。
    下面的这行会在新窗口打开文档：
    <a href="http://www.w3school.com.cn/" target="_blank">Visit W3School!</a>

    <!-- <hr>创建一个水平线 -->
    <hr></hr>

    <img src="w3.school.jpg" width="104" height="142">
    替换文本属性（Alt）
    alt 属性用来为图像定义一串预备的可替换的文本。替换文本属性的值是用户定义的。
    <img src="boat.gif" alt="Big Boat">
    当浏览器无法载入图像时，替换文本属性可告诉读者他们失去的信息。
    此时，浏览器将显示这个替代性的文本而不是图像。
    为页面上的图像都加上替换文本属性是个好习惯，这样有助于更好的显示信息，
    并且对于那些使用纯文本浏览器的人来说是非常有用的。

    ==========================================================================

    <!-- 样式 -->

    <!-- HTML 样式实例 - 背景颜色 -->
    <body style="background-color:yellow">
    <h2 style="background-color:red">This is a heading</h2>
    <p style="background-color:green">This is a paragraph.</p>
    </body>

    <!-- HTML 样式实例 - 字体、颜色和尺寸 -->
     <!-- font-family、color 以及 font-size 属性分别
      定义元素中文本的字体系列、颜色和字体尺寸： -->
    <body>
    <h1 style="font-family:verdana">A heading</h1>
    <p style="font-family:arial;color:red;font-size:20px;">A paragraph.</p>
    </body>

    <!-- HTML 样式实例 - 文本对齐 -->
    <!-- text-align 属性规定了元素中文本的水平对齐方式： -->
    <body>
    <h1 style="text-align:center">This is a heading</h1>
    <p>The heading above is aligned to the center of this page.</p>
    </body>

    文本格式化标签
    标签	描述
    <!-- <b>	定义粗体文本。
    <em>	定义着重文字。
    <i>	定义斜体字。
    <small>	定义小号字。
    <strong>	定义加重语气。
    <sub>	定义下标字。
    <sup>	定义上标字。
    <ins>	定义插入字。
    <del>	定义删除字。 -->

    ==========================================================================

    如何使用样式
    当浏览器读到一个样式表，它就会按照这个样式表来对文档进行格式化。有以下三种方式来插入样式表：

    外部样式表
    当样式需要被应用到很多页面的时候，外部样式表将是理想的选择。使用外部样式表，你就可以通过更改一个文件来改变整个站点的外观。
    <head>
    <link rel="stylesheet" type="text/css" href="mystyle.css">
    </head>


    内部样式表
    当单个文件需要特别样式时，就可以使用内部样式表。你可以在 head 部分通过 style标签定义内部样式表。
    <head>
    <style type="text/css">
    body {background-color: red}
    p {margin-left: 20px}
    </style>
    </head>


    内联样式
    当特殊的样式需要应用到个别元素时，就可以使用内联样式。使用内联样式的方法是在相关的标签中使用样式属性。样式属性可以包含任何 CSS 属性。以下实例显示出如何改变段落的颜色和左外边距。
    <p style="color: red; margin-left: 20px">
    This is a paragraph
    </p>

    ==========================================================================

    表格
    表格由 <table> 标签来定义。每个表格均有若干行（由 <tr> 标签定义），
        每行被分割为若干单元格（由 <td> 标签定义）。
            字母 td 指表格数据（table data），即数据单元格的内容。
            数据单元格可以包含文本、图片、列表、段落、表单、水平线、表格等等。

    <table border="1">
    <tr>
    <td>row 1, cell 1</td>
    <td>row 1, cell 2</td>
    </tr>
    <tr>
    <td>row 2, cell 1</td>
    <td>row 2, cell 2</td>
    </tr>
    </table>
    在浏览器显示如下：

    row 1, cell 1	row 1, cell 2
    row 2, cell 1	row 2, cell 2


    表格和边框属性
    如果不定义边框属性，表格将不显示边框。有时这很有用，但是大多数时候，我们希望显示边框。

    使用边框属性来显示一个带有边框的表格：

    <table border="1">
    <tr>
    <td>Row 1, cell 1</td>
    <td>Row 1, cell 2</td>
    </tr>
    </table>
    表格的表头
    表格的表头使用 <th> 标签进行定义。

    大多数浏览器会把表头显示为粗体居中的文本：

    <table border="1">
    <tr>
    <th>Heading</th>
    <th>Another Heading</th>
    </tr>
    <tr>
    <td>row 1, cell 1</td>
    <td>row 1, cell 2</td>
    </tr>
    <tr>
    <td>row 2, cell 1</td>
    <td>row 2, cell 2</td>
    </tr>
    </table>
    在浏览器显示如下：

    Heading	        Another Heading
    row 1, cell 1	row 1, cell 2
    row 2, cell 1	row 2, cell 2
    表格中的空单元格
    在一些浏览器中，没有内容的表格单元显示得不太好。如果某个单元格是空的（没有内容），浏览器可能无法显示出这个单元格的边框。

    <table border="1">
    <tr>
    <td>row 1, cell 1</td>
    <td>row 1, cell 2</td>
    </tr>
    <tr>
    <td></td>
    <td>row 2, cell 2</td>
    </tr>
    </table>
    浏览器可能会这样显示：

    表格中的空单元格
    注意：这个空的单元格的边框没有被显示出来。为了避免这种情况，在空单元格中添加一个空格占位符，就可以将边框显示出来。

    <table border="1">
    <tr>
    <td>row 1, cell 1</td>
    <td>row 1, cell 2</td>
    </tr>
    <tr>
    <td>&nbsp;</td>
    <td>row 2, cell 2</td>
    </tr>
    </table>
    在浏览器中显示如下：

    row 1, cell 1	row 1, cell 2
                    row 2, cell 2

    ===========================================================================
    无序列表
    无序列表是一个项目的列表，此列项目使用粗体圆点（典型的小黑圆圈）进行标记。

    无序列表始于 <ul> 标签。每个列表项始于 <li>。

    <ul>
    <li>Coffee</li>
    <li>Milk</li>
    </ul>
    浏览器显示如下：
        ·Coffee
        ·Milk
    列表项内部可以使用段落、换行符、图片、链接以及其他列表等等。

    有序列表
    同样，有序列表也是一列项目，列表项目使用数字进行标记。

    有序列表始于 <ol> 标签。每个列表项始于 <li> 标签。

    <ol>
    <li>Coffee</li>
    <li>Milk</li>
    </ol>
    浏览器显示如下：
        1.Coffee
        2.Milk
    列表项内部可以使用段落、换行符、图片、链接以及其他列表等等。

    定义列表
    自定义列表不仅仅是一列项目，而是项目及其注释的组合。

    自定义列表以 <dl> 标签开始。每个自定义列表项以 <dt> 开始。每个自定义列表项的定义以 <dd> 开始。

    <dl>
    <dt>Coffee</dt>
    <dd>Black hot drink</dd>
    <dt>Milk</dt>
    <dd>White cold drink</dd>
    </dl>
    浏览器显示如下：
    Coffee
        Black hot drink
    Milk
        White cold drink
    定义列表的列表项内部可以使用段落、换行符、图片、链接以及其他列表等等。

    ============================================================================
    HTML 块元素和行内元素

    可以通过 <div> 和 <span> 将 HTML 元素组合起来。

    HTML 块元素
    大多数 HTML 元素被定义为块级元素或内联元素。

    编者注：“块级元素”译为 block level element，“内联元素”译为 inline element。

    块级元素在浏览器显示时，通常会以新行来开始（和结束）。

    例子：<h1>, <p>, <ul>, <table>

    HTML 内联元素
    内联元素在显示时通常不会以新行开始。

    例子：<b>, <td>, <a>, <img>

    HTML <div> 元素
    HTML <div> 元素是块级元素，它是可用于组合其他 HTML 元素的容器。

    <div> 元素没有特定的含义。除此之外，由于它属于块级元素，浏览器会在其前后显示折行。

    如果与 CSS 一同使用，<div> 元素可用于对大的内容块设置样式属性。

    <div> 元素的另一个常见的用途是文档布局。它取代了使用表格定义布局的老式方法。
        使用 <table> 元素进行文档布局不是表格的正确用法。<table> 元素的作用是显示表格化的数据。

    HTML <span> 元素
    HTML <span> 元素是内联元素，可用作文本的容器。

    <span> 元素也没有特定的含义。

    当与 CSS 一同使用时，<span> 元素可用于为部分文本设置样式属性。

    ===========================================================================
    HTML id 属性
    HTML id 属性用于 为HTML 元素指定唯一的 id。

        一个 HTML文档中不能存在多个有相同 id 的元素。

        使用 id 属性
        id 属性指定 HTML 元素的唯一 ID。 id 属性的值在 HTML 文档中必须是唯一的。

        id 属性用于指向样式表中的特定样式声明。JavaScript 也可使用它来访问和操作拥有特定 ID 的元素。

        id 的语法是：写一个井号 (#)，后跟一个 id 名称。然后，在花括号 {} 中定义 CSS 属性。

        下面的例子中我们有一个 <h1> 元素，它指向 id 名称 "myHeader"。这个 <h1> 元素将根据 head 部分中的 #myHeader 样式定义进行样式设置：

        实例
        <!DOCTYPE html>
        <html>
        <head>
        <style>
        #myHeader {
        background-color: lightblue;
        color: black;
        padding: 40px;
        text-align: center;
        }
        </style>
        </head>
        <body>

        <h1 id="myHeader">My Header</h1>

        </body>
        </html>

        Class 与 ID 的差异
        同一个类名可以由多个 HTML 元素使用，而一个 id 名称只能由页面中的一个 HTML 元素使用：

        实例
        <style>
        /* 设置 id 为 "myHeader" 的元素的样式 */
        #myHeader {
        background-color: lightblue;
        color: black;
        padding: 40px;
        text-align: center;
        }

        /* 设置类名为 "city" 的所有元素的样式 */
        .city {
        background-color: tomato;
        color: white;
        padding: 10px;
        }
        </style>

        <!-- 拥有唯一 id 的元素 -->
        <h1 id="myHeader">My Cities</h1>

        <!-- 拥有相同类名的多个元素 -->
        <h2 class="city">London</h2>
        <p>London is the capital of England.</p>

        <h2 class="city">Paris</h2>
        <p>Paris is the capital of France.</p>

        <h2 class="city">Tokyo</h2>
        <p>Tokyo is the capital of Japan.</p>

    =========================================================================
    HTML 表单
    HTML 表单用于收集用户输入。
    HTML 表单用于用户输入数据，这些数据将发送到服务器进行处理。
    HTML 表单由 <form> 标签定义。表单内的各种输入元素由 <input> 标签定义。
    表单还可以包含文本域、按钮、单选按钮、复选框等
    文本输入
    <input> 元素
        <input> 元素是最重要的表单元素。

        <input> 元素有很多形态，根据不同的 type 属性。

        这是本章中使用的类型：

        类型	描述
        text	定义常规文本输入。
        radio	定义单选按钮输入（选择多个选择之一）
        submit	定义提交按钮（提交表单）
        注释：您稍后将在本教程学到更多有关输入类型的知识。

        文本输入
        <input type="text"> 定义用于文本输入的单行输入字段：

        实例
        <form>
        First name:<br>
        <input type="text" name="firstname">
        <br>
        Last name:<br>
        <input type="text" name="lastname">
        </form> 


    单选按钮输入
    <input type="radio"> 定义单选按钮。
        单选按钮允许用户在有限数量的选项中选择其中之一：

        实例
        <form>
        <input type="radio" name="sex" value="male" checked>Male
        <br>
        <input type="radio" name="sex" value="female">Female
        </form> 

    提交按钮
    <input type="submit"> 定义用于向表单处理程序（form-handler）提交表单的按钮。
        表单处理程序通常是包含用来处理输入数据的脚本的服务器页面。

        表单处理程序在表单的 action 属性中指定：

        实例
        <form action="action_page.php">
        First name:<br>
        <input type="text" name="firstname" value="Mickey">
        <br>
        Last name:<br>
        <input type="text" name="lastname" value="Mouse">
        <br><br>
        <input type="submit" value="Submit">
        </form>


    Action 属性
    action 属性定义在提交表单时执行的动作。
        向服务器提交表单的通常做法是使用提交按钮。

        通常，表单会被提交到 web 服务器上的网页。

        在上面的例子中，指定了某个服务器脚本来处理被提交表单：

        <form action="action_page.php">
        如果省略 action 属性，则 action 会被设置为当前页面。

    Method 属性
    method 属性规定在提交表单时所用的 HTTP 方法（GET 或 POST）：
    <form action="action_page.php" method="GET">
    或：

    <form action="action_page.php" method="POST">
    何时使用 GET？
    您能够使用 GET（默认方法）：
    如果表单提交是被动的（比如搜索引擎查询），并且没有敏感信息。
    当您使用 GET 时，表单数据在页面地址栏中是可见的：
    action_page.php?firstname=Mickey&lastname=Mouse
    注释：GET 最适合少量数据的提交。浏览器会设定容量限制。

    何时使用 POST？
    您应该使用 POST：
    如果表单正在更新数据，或者包含敏感信息（例如密码）。
    POST 的安全性更好，因为在页面地址栏中被提交的数据是不可见的。


    Name 属性
    如果要正确地被提交，每个输入字段必须设置一个 name 属性。

    本例只会提交 "Last name" 输入字段：

    实例
    <form action="action_page.php">
    First name:<br>
    <input type="text" value="Mickey">
    <br>
    Last name:<br>
    <input type="text" name="lastname" value="Mouse">
    <br><br>
    <input type="submit" value="Submit">
    </form> 


    Target 属性
    target 属性规定提交表单后在何处显示响应。
    target 属性可设置以下值之一：

    值	    描述
    _blank	响应显示在新窗口或选项卡中。
    _self	响应显示在当前窗口中。
    _parent	响应显示在父框架中。
    _top	响应显示在窗口的整个 body 中。
    framename	响应显示在命名的 iframe 中。
    默认值为 _self，这意味着响应将在当前窗口中打开。

    实例
    此处，提交的结果将在新的浏览器标签中打开：
    <form action="/action_page.php" target="_blank">

    ========================================================================
    HTML表单元素
    <input> 元素
        最重要的表单元素是 <input> 元素。

        <input> 元素根据不同的 type 属性，可以变化为多种形态。

        注释：下一章讲解所有 HTML 输入类型。

        <select> 元素（下拉列表）
        <select> 元素定义下拉列表：

        实例
        <select name="cars">
        <option value="volvo">Volvo</option>
        <option value="saab">Saab</option>
        <option value="fiat">Fiat</option>
        <option value="audi">Audi</option>
        </select>

        <option> 元素定义待选择的选项。
        列表通常会把首个选项显示为被选选项。
        您能够通过添加 selected 属性来定义预定义选项。

        实例
        <option value="fiat" selected>Fiat</option>


    <textarea> 元素
        <textarea> 元素定义多行输入字段（文本域）：

        实例
        <textarea name="message" rows="10" cols="30">The cat was playing in the garden.
    </textarea>

    <button> 元素
        <button> 元素定义可点击的按钮：

        实例
        <button type="button" onclick="alert('Hello World!')">Click Me!</button>

    ========================================================================
    HTML输入类型
    HTML 提供了多种不同类型的输入字段。以下是最常用的输入类型：
    <input type="text"></input>
        定义单行文本输入字段。
        默认值是单行文本。
    <input type="password"></input>
        定义密码输入字段。输入的字符会被掩盖。
    <input type="submit"></input>
        定义提交按钮。点击按钮后，表单数据会被发送到服务器。        
    <input type="radio"></input>
        定义单选按钮。用户可以从一组选项中选择一个选项。
        单选按钮通常被用于单选列表。
    <input type="checkbox"></input>
        定义复选框。用户可以从一组选项中选择多个选项。
        复选框通常被用于多选列表。
    <input type="button"></input>
        定义可点击的按钮。按钮没有默认行为。
        您必须使用 JavaScript 来定义按钮行为。
    ========================================================================
    HTML Input 属性
    属性	        描述
    type	    定义输入字段的类型。
    value	    定义输入字段的默认值。
    name	    定义输入字段的名称。
    size	    定义输入字段的宽度（以字符为单位）。
    maxlength	定义输入字段的最大长度（以字符为单位）。
    placeholder	定义输入字段的提示信息。
    required	规定输入字段是必填的。
    autofocus	规定输入字段自动获得焦点。
    autocomplete	规定浏览器是否应该自动完成输入字段。
    readonly	规定输入字段是只读的。
    disabled	规定输入字段是禁用的。

</body>
</html>