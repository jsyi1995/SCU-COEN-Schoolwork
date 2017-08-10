<?php
  $conn = oci_connect('jyi', 'XMRmk2proto', '//dbserver.engr.scu.edu/db11g');
  if(!$conn){
    alert("Could not connect to database");
    exit;
  }
  
  $sql = "SELECT city, ROUND(AVG(monthlyRent),2) FROM Property GROUP BY city";
  $sql_stmt = OCIParse($conn, $sql);
  OCIExecute($sql_stmt);
  $num_columns = OCINumCols($sql_stmt);
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
  <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1.0"/>
  <title>GreenField Rental Management Incorporated</title>

  <!-- CSS  -->
  <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
  <link href="css/materialize.css" type="text/css" rel="stylesheet" media="screen,projection"/>
  <link href="css/style.css" type="text/css" rel="stylesheet" media="screen,projection"/>
</head>
<body>
  <nav class="light-blue lighten-1" role="navigation">
    <div class="nav-wrapper container"><a id="logo-container" href="index.html" class="brand-logo">GreenField Rental Management Inc.</a>
      <ul class="right hide-on-med-and-down">
        <li><a href="index.html">Home</a></li>
      </ul>

      <ul id="nav-mobile" class="side-nav">
        <li><a href="index.html">Home</a></li>
      </ul>
      <a href="#" data-activates="nav-mobile" class="button-collapse"><i class="material-icons">menu</i></a>
    </div>
    </nav>

  <div class="container">
    <div class="section">
      <h3>Average Rent for Each City</h3>
      <div class="row">
          <div class="input-field col s4">
              <input id="myInput" type="text" onkeyup="searchfunc()" class="active validate">
              <label for="myInput">Search City</label>
            </div>
      </div>
      <div class="row">
        <table class="striped centered" id="testTable">
	    <thead>
	      <TR><TH>City</TH><TH>Average Rent</TH></TR>
	    </thead>
	  <?php
	    while (OCIFetch($sql_stmt)) {
	      echo "<TR>";
	      for ($i = 1; $i <= $num_columns; $i++) {
		      $column_value = OCIResult($sql_stmt, $i);
		      echo "<TD>$column_value</TD>";
	      }
	      echo "</TR>";
	    }
	  ?>
	  </table>
      </div>
    </div>
  </div>

  <!--  Scripts-->
  <script src="https://code.jquery.com/jquery-2.1.1.min.js"></script>
  <script src="js/materialize.js"></script>
  <script src="js/init.js"></script>
  <script>
    function searchfunc() {
  // Declare variables 
  var input, filter, table, tr, td, i;
  input = document.getElementById("myInput");
  filter = input.value.toUpperCase();
  table = document.getElementById("testTable");
  tr = table.getElementsByTagName("tr");

  // Loop through all table rows, and hide those who don't match the search query
  for (i = 0; i < tr.length; i++) {
    td = tr[i].getElementsByTagName("td")[0];
    if (td) {
      if (td.innerHTML.toUpperCase().indexOf(filter) > -1) {
        tr[i].style.display = "";
      } else {
        tr[i].style.display = "none";
      }
    } 
  }
}
  </script>
  </body>
</html>
