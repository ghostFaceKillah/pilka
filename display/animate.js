$(function() { 
  var ctx = $('#canvas')[0].getContext("2d");

  function parseArray(A) {
    for (var i=0; i<A.length; i++) {
      for (var j=0; j<A[i].length; j++) {
	if (A[i][j] != "") {
	  A[i][j] = parseInt(A[i][j]);
	} else {
	  A[i].splice(j, 1);
	};
      };
    };
  };

  function parse(data) {
    A = data.split("\n");
    kropki = [];
    for (var i=5; A[i] != "vertical"; i++) {
      kropki.push(A[i].split(" "));
    };
    parseArray(kropki);

    dots = [];
    for (var i=0; i<kropki.length; i++) {
      for (var j=0; j<kropki[i].length; j++) {
	if (kropki[i][j] == 1) {
	  a = {};
	  a.y = i*30 + 30;
	  a.x = j*30 + 30;
	  dots.push(a);
	};
      };
    };
  };



  function resolve() { 

    clearCanvas(ctx);
    for (i in dots) {
      drawDot(ctx, dots[i]);
    }

    $('#canvas')[0].height/2
      frame(ctx, $('#canvas')[0].width/2, $('#canvas')[0].height/2,  //draw a frame
          $('#canvas')[0].width, $('#canvas')[0].height);
  };


  $.get('test.state', function(data) {
    parse(data);
    resolve();
  } );
  // var timer = setInterval(function(){ resolve()} , 10) ;
});
