// Main calling top and base triangles
function main()
{
	return union(top(),base());
}

// base triangle containing the 3 hinges to hold the wheels
function base()
{
	var t1= difference(cylinder({r: 5,h:1, fn: 3 }),gap());
	var x= union(t1.translate([0,0,3]).rotateX(180),hinge().translate([-1,1.2,-3.8]),hinge().translate([-1,-1.5,-3.8]),hinge().translate([1.5,-0,-3.8]));
	var y= difference(x,hole().translate([-2.2,3.8,-5]),hole().translate([-2.2,-3.8,-5]),hole().translate([4.2,0,-5]));
	return y;
}

// top triangle containing the 3 hinges to hold the wheels and also the notches so that the triangles fit properly
function top()
{
	var t1= difference(cylinder({r: 5,h:1, fn: 3 }),gap());
	var x= union(t1,notch1(),notch2(),notch3(),hinge().translate([-1,1.2,0.3]),hinge().translate([-1,-1.5,0.3]),hinge().translate([1.5,-0,0.3]));
	var y= difference(x,hole().translate([-2.2,3.8,0]),hole().translate([-2.2,-3.8,0]),hole().translate([4.2,0,0]));
	return y;
}

//Notch 1 for top triangle
function notch1()
{
	var r= cube({size: [0.2,6.7,1]});
	return r.translate([1.8,-3.35,-3.5]).rotateZ(60);
}

//Notch 2 for top triangle
function notch2()
{
	var r= cube({size: [0.2,6.7,1]});
	return r.translate([-2,-3.35,-3.5]).rotateZ(120);
}

//Notch 3 for top triangle
function notch3()
{
	var r= cube({size: [0.2,6.7,1]});
	return r.translate([1.8,-3.35,-3.5]).rotateZ(180);
}

//Hinge to hold the wheels in place
function hinge()
{
	var h=cube({size:[0.3,0.3,0.5]});
	return h;
}

//Holes for the strings to pass through the triangles
function hole()
{
	var h=cylinder({r: 0.05, h: 3}); 
	return h;
}

//Space for the wheels to fit into the triangles
function gap()
{
	var t1= cylinder({r: 4,h:0.5, fn: 3 });
	return union(t1,t1.translate([0,0,3.2]));
}

