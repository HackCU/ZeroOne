Object3D* cube = initObject();

addPointToCloud(cube->cloud, initPointWithValues(-1.0,-1.0,-1.0));
addPointToCloud(cube->cloud, initPointWithValues( 1.0,-1.0,-1.0));
addPointToCloud(cube->cloud, initPointWithValues( 1.0,-1.0, 1.0));
addPointToCloud(cube->cloud, initPointWithValues(-1.0,-1.0, 1.0));
addPointToCloud(cube->cloud, initPointWithValues(-1.0, 1.0,-1.0));
addPointToCloud(cube->cloud, initPointWithValues( 1.0, 1.0,-1.0));
addPointToCloud(cube->cloud, initPointWithValues( 1.0, 1.0, 1.0));
addPointToCloud(cube->cloud, initPointWithValues(-1.0, 1.0, 1.0));

addTriangle(cube->list, initTriangleWithValues(1,4,3));
addTriangle(cube->list, initTriangleWithValues(3,2,1));

addTriangle(cube->list, initTriangleWithValues(2,3,7));
addTriangle(cube->list, initTriangleWithValues(7,6,2));

addTriangle(cube->list, initTriangleWithValues(7,3,4));
addTriangle(cube->list, initTriangleWithValues(4,8,7));


addTriangle(cube->list, initTriangleWithValues(5,1,2));
addTriangle(cube->list, initTriangleWithValues(2,6,5));

addTriangle(cube->list, initTriangleWithValues(5,8,4));
addTriangle(cube->list, initTriangleWithValues(4,1,5));

addTriangle(cube->list, initTriangleWithValues(6,7,8));
addTriangle(cube->list, initTriangleWithValues(8,5,6));
