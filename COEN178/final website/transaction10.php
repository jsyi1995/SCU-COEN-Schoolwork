<?php
  $conn = oci_connect('jyi', 'XMRmk2proto', '//dbserver.engr.scu.edu/db11g');
  if(!$conn){
    alert("Could not connect to database");
    exit;
  }
  
  $sql = "SELECT custName, street, city, zip
	     FROM Lease JOIN Property
	     ON Lease.propNum = Property.propNum
	     WHERE endDate > SYSDATE
	     AND endDate < SYSDATE + 60";
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
      <h3>Properties with Leases that will Expire Soon</h3>
      <h5>Note: "Soon" is two months from now</h5>
      <div class="row">
        <table class="striped centered">
	    <thead>
	      <TR><TH>Customer Name</TH><TH>Street</TH><TH>City</TH><TH>Zip</TH></TR>
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

  </body>
</html>
