$(function() { 
  var ctx = $('#canvas')[0].getContext("2d");

  function parseArray(A, from, to) {

    target = [];
    for (var i=from; i <= to ; i++) {
      target.push(A[i].split(" "));
    };

    for (var i=0; i<target.length; i++) {
      for (var j=0; j<target[i].length; j++) {
	if (target[i][j] != "") {
	  target[i][j] = parseInt(target[i][j]);
	} else {
	  target[i].splice(j, 1);
	};
      };
    };
    return target;
  };

  function parse(data) {
    scale = 30;
    A = data.split("\n");
    kropki = parseArray(A, 5,17);
    vertical = parseArray(A, 19, 30);
    horizontal = parseArray(A, 32, 42);
    diags = parseArray(A, 44, 55);
    adiags = parseArray(A, 57, 68);
    
    // create dots for drawing
    dots = [];
    bleak_dots = [];
    for (var i=0; i<kropki.length; i++) {
      for (var j=0; j<kropki[i].length; j++) {
	a = {};
	a.y = (kropki.length-i-1)*scale + scale;
	a.x = j*scale + scale - 2;
	if (kropki[i][j] == 1) {
	  dots.push(a);
	} else {
	  bleak_dots.push(a);
	};
      };
    };

    // create vertical lines for drawing
    v_lines = [];
    for (var i=0; i<vertical.length; i++) {
      for (var j=0; j<vertical[i].length; j++) {
	if (vertical[i][j] == 1) {
	  line = {};
	  line.from_x = j*scale + scale;
	  line.from_y = (vertical.length-i-1)*scale + scale;
	  line.to_x = j*scale + scale;
	  line.to_y = (vertical.length-i)*scale + scale;
	  v_lines.push(line);
	};
      };
    };

    // create horizontal lines for drawing
    h_lines = [];
    for (var i=0; i<horizontal.length; i++) {
      for (var j=0; j<horizontal[i].length; j++) {
	if (horizontal[i][j] == 1) {
	  line = {};
	  line.from_x = (j-1)*scale + scale;
	  line.from_y = (horizontal.length-i)*scale + scale + 2;
	  line.to_x = j*scale + scale;
	  line.to_y = (horizontal.length-i)*scale + scale + 2;
	  h_lines.push(line);
	};
      };
    };

    // create diags lines for drawing
    diag_lines = [];
    for (var i=0; i<diags.length; i++) {
      for (var j=0; j<diags[i].length; j++) {
	if (diags[i][j] == 1) {
	  line = {};
	  line.from_x = j*scale + scale;
	  line.from_y = (diags.length-i-1)*scale + scale + 2;
	  line.to_x = (j-1)*scale + scale;
	  line.to_y = (diags.length-i)*scale + scale + 2;
	  diag_lines.push(line);
	};
      };
    };

    // create adiags lines for drawing
    adiag_lines = [];
    for (var i=0; i<adiags.length; i++) {
      for (var j=0; j<adiags[i].length; j++) {
	if (adiags[i][j] == 1) {
	  line = {};
	  line.from_x = (j-1)*scale + scale;
	  line.from_y = (adiags.length-i-1)*scale + scale + 2;
	  line.to_x = j*scale + scale;
	  line.to_y = (adiags.length-i)*scale + scale + 2;
	  adiag_lines.push(line);
	};
      };
    };
  };



  function resolve() { 

    clearCanvas(ctx);
    for (i in dots) {
      drawDot(ctx, "black", dots[i]);
    }
    for (i in bleak_dots) {
      drawDot(ctx, "bleak", bleak_dots[i]);
    }
    for (i in v_lines) {
      drawLine(ctx, v_lines[i]);
    }
    for (i in h_lines) {
      drawLine(ctx, h_lines[i]);
    }
    for (i in diag_lines) {
      drawLine(ctx, diag_lines[i]);
    }
    for (i in adiag_lines) {
      drawLine(ctx, adiag_lines[i]);
    }
    drawFrame(ctx);
  };


  $.get('test.state', function(data) {
    parse(data);
    resolve();
  } );
  // var timer = setInterval(function(){ resolve()} , 10) ;
});
