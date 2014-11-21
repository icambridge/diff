<?hh

namespace Diff\Generator;

class Generic<T> implements Generator
{
    public function __construct(private T $from, private T $to): void {}

    public function diff() : string
    {
        $message = "-".(string)$this->from."\n";
        $message .= "+".(string)$this->to."\n";
        return $message;
    }
}
