<p>
    Welcome, <strong><?=$username?>!</strong> Your cash is <strong>$<?=number_format($cash, 2)?></strong>
</p>

<table class="table table-hover">
    <thead>
        <tr>
            <th>Name</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
        </tr>
    </thead>
    <tbody>
        <?php

        foreach ($positions as $position)
        {
            print("<tr>");
            print("<td>" . $position["name"] . "</td>");
            print("<td>" . $position["symbol"] . "</td>");
            print("<td>" . $position["shares"] . "</td>");
            print("<td>" . $position["price"] . "</td>");
            print("</tr>");
        }

    ?>
    </tbody>
</table>