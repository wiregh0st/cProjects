<!DOCTYPE html>
<?php
if(isset($_POST['name']) && isset($_POST['address']) && ($_POST['hotSand'] > 0) && ($_POST['coldSand'] > 0) && ($_POST['server'] > 0))
        {
            $name = "wr0ng us3r";
            $address = "400 Bad address";
            if($_POST['name'] != '');
            {
                $name = $_POST['name'];
            }
            if($_POST['address'] != '');
            {
                $address = $_POST['address'];
            }
            $numHotSand = $_POST['hotSand'];
            $numColdSand = $_POST['coldSand'];
            $numServer = $_POST['server'];
            $hotSandPrice = 4.99;
            $coldSandPrice = 5.99;
            $serverPrice = 6.99;
            $subtotal = ($numHotSand*$hotSandPrice) + ($numColdSand*$coldSandPrice) + ($numServer*$serverPrice);

            echo nl2br("Receipt for $name\n");
            echo nl2br("$address\n\n");
            echo nl2br("$numHotSand x Hot PHP Sandwich\t\n");
            echo nl2br("$numColdSand x Cold PHP sandwich\t\n");
            echo nl2br("$numServer x PHP with a side of Server\t\n");
            echo nl2br("Subtotal: $subtotal\n");
            $SCtax = 0.06;
            $yorkTax = 0.01;
            $hospTax = 0.02;
            $SCtax = $SCtax * $subtotal;
            $yorkTax = $yorkTax * $subtotal;
            $hospTax = $hospTax * $subtotal;
            echo nl2br("SC Tax: $SCtax\nYork Tax: $yorkTax\nHospitality Tax: $hospTax\n");
            $total = $subtotal + $SCtax + $yorkTax + $hospTax;
            echo "Total: $total";


        }
        else
        {
            echo "Please fill out the form completely to continue. Negatives are not allowed for food amounts!";
        }
        ?>
</html>