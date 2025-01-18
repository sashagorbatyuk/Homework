using System;

public class CreditCard
{
    public string CardNumber { get; set; }
    public string OwnerName { get; set; }
    public DateTime ExpirationDate { get; set; }
    public string PIN { get; set; }
    public decimal CreditLimit { get; set; }
    public decimal Balance { get; set; }

    // Події
    public event Action<decimal> OnDeposit;
    public event Action<decimal> OnWithdrawal;
    public event Action OnStartUsingCredit;
    public event Action OnCreditLimitReached;
    public event Action<string> OnPinChanged;

    // Метод для поповнення рахунку
    public void Deposit(decimal amount)
    {
        Balance += amount;
        OnDeposit?.Invoke(amount);
    }

    // Метод для витрати коштів з рахунку
    public void Withdraw(decimal amount)
    {
        if (Balance - amount < -CreditLimit)
        {
            Console.WriteLine("Недостатньо коштів на рахунку для виконання операції.");
        }
        else
        {
            Balance -= amount;
            OnWithdrawal?.Invoke(amount);

            // Якщо використано кредит
            if (Balance < 0 && OnStartUsingCredit != null)
            {
                OnStartUsingCredit.Invoke();
            }

            // Якщо досягнуто ліміту
            if (Balance <= -CreditLimit && OnCreditLimitReached != null)
            {
                OnCreditLimitReached.Invoke();
            }
        }
    }

    // Метод для зміни PIN
    public void ChangePin(string newPin)
    {
        PIN = newPin;
        OnPinChanged?.Invoke(newPin);
    }
}