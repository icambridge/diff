<?hh //strict

namespace Diff\Generator;

class Mismatch implements Generator
{
    public function __construct(private mixed $from, private mixed $to): void {}

    public function diff(): string
    {
        $message = "-" . $this->description($this->from);
        $message .= "+" . $this->description($this->to);

        return $message;
    }

    private function description(mixed $var): string
    {
        $type = gettype($var);
        if ("array" == $type) {
            return "<array>\n";
        }

        return "<$type> $var\n";
    }
}
