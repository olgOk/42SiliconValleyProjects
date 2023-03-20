SELECT UPPER(last_name) AS 'NAME', first_name, subscription.price FROM user_card
INNER JOIN member ON member.id_user_card = user_card.id_user
INNER JOIN subscription ON subscription.id_sub = member.id_sub
WHERE subscription.price > 42
ORDER BY last_name, first_name ASC;